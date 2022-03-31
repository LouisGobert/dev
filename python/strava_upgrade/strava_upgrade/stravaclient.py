#!/usr/bin/env python
# coding: utf-8

import webbrowser
import requests
import json
import logging
import pickle
from bs4 import BeautifulSoup
import datetime as dt
import os
import time
import pandas as pd
import utils
import itertools
import stravadata
import config
import getpass


# requests
URL_SITE = 'https://www.strava.com/'
URL_GET_USER_INFO = f'{URL_SITE}/api/v3/athlete?='
MAX_PER_PAGE = 200


FILE_SESSION = 'output/private/session.pkl'
FILE_USER_ACCES_TOKEN = "output/private/user_acces_token.token"


class StravaClient:

    def __init__(self):

        # Custom option
        self.client_id = 0
        self.client_secret = 'un_token'
        self.acces_token = 'Bien_essayé'
        self.email = 'louis.gobert@gmail.com'


        self.user_acces_token = None
        self.login()
        self.get_user_acces_token()
        self.get_user_info()

    def login(self):

        try:
            with open(FILE_SESSION, 'rb') as f:
                self.session = pickle.load(f)

                if self.session.get(f'{URL_SITE}dashboard').status_code == 200:
                    return True

        except IOError:
            logging.info(f'Error while opening {FILE_SESSION}')

        self.session = requests.Session()

        html = self.session.get("https://www.strava.com/login")

        soup = BeautifulSoup(html.content, 'html.parser')
        authenticity_token = soup.find(
            'input', {'name': 'authenticity_token'})['value']
        logging.debug(f'Athenticity token : {authenticity_token}')

        login_playload = {
            'email': self.email,
            'password': getpass.getpass('Password : '), 
            'utf-8': '✓',
            'authenticity_token': authenticity_token}

        logging.info('Request logging...')
        self.session.post("https://www.strava.com/session", login_playload)

        if self.session.get(f'{URL_SITE}dashboard').status_code == 200:
            logging.info('Connection succes')

            with open(FILE_SESSION, 'wb') as f:
                pickle.dump(self.session, f)

            return True
        
        logging.info('Connection error.')
        return False

    def download_gpx(self, activity_id, activity_date):
        """
        Fonction qui permet de télécharger un gpx donnée grace à sont id.
        """
        
        get_gpx_url = f'https://www.strava.com/activities/{activity_id}/export_gpx'

        r = self.session.get(get_gpx_url, allow_redirects=True, headers=self.authorized_header)

        if '<?xml version="1.0" encoding="UTF-8"?>' in r.text:

            # Format name
            with open(f'{config.GPX_FOLDER}{activity_date}-{activity_id}.gpx', 'wb') as f:
                f.write(r.content)
        else:
            logging.info(f'Activity {activity_id} have not a gpx')

    def download_all_gpx(self):

        df_activities = utils.read_json_to_df(config.ACTIVITIES_JSON)[['id', 'date']]

        if df_activities.empty:
            return
        
        for i, activity in df_activities.iterrows():
            logging.info(f'Downloading {i+1}/{len(df_activities)} gpx.')
            self.download_gpx(activity_id=activity['id'], activity_date=activity['date'])


    def dowload_all_activities(self, download_all=False):
        """

        Get all activities if refresh_all = True or read src/activities.json for 
        know the last activity and scrap from last know activitie to now.

        """

        if download_all and os.path.exists(config.ACTIVITIES_JSON):
            os.remove(config.ACTIVITIES_JSON)

        before = int(time.time())

        if download_all:
            after = int(dt.datetime.strptime(
                self.created_at, "%Y-%m-%d").timestamp())
        else:
            activities = utils.read_json_to_df(config.ACTIVITIES_JSON)
            if not activities.empty:
                
                after = activities.iloc[0]['date'] + pd.tseries.offsets.DateOffset(seconds=3600)
                after = int(after.to_pydatetime().timestamp())
            else:
                after = int(dt.datetime.strptime(self.created_at,
                            '%Y-%m-%dT%H:%M:%SZ').timestamp()) + 10000

        
        playload = {'before': before,
                    'after': after,
                    'per_page': MAX_PER_PAGE}

        page = 1
        new_data = []
        data = None

        logging.info('Starting downloading activities...')

        while data is None or len(data) == MAX_PER_PAGE:

            playload['page'] = page
            response = requests.get(
                url='https://www.strava.com/api/v3/athlete/activities',
                params=playload,
                headers=self.authorized_header)

            if response.status_code != 200:
                logging.error('Error when attenpt to download all activities. Bad reponse code')
                return

            data = json.loads(response.text)

            if data:
                logging.info('Downloading {0} new activities'.format(len(data)))
                new_data = list(itertools.chain(new_data, data))
                page += 1

        # Try if new activity detect and add to list
        if new_data:

            df_old_activities = utils.read_json_to_df(config.ACTIVITIES_JSON)

            new_data = stravadata.data_processing(pd.DataFrame(new_data))

            if not df_old_activities.empty:
                df_old_activities = df_old_activities.append(new_data).sort_values(
                    by='date', ascending=False)
            else:
                df_old_activities = new_data.sort_values(
                    by='date', ascending=False)

            utils.write_df_to_json(df_old_activities, config.ACTIVITIES_JSON)
            
            
    def get_activity_stream(self, id_activity):
        playload = {
            'keys': ['heartrate'],
            'key_by_type': True
        }

        response = self.session.get(
            url=f'{URL_SITE}activities/{id_activity}/streams',
            headers=self.authorized_header,
            params=playload
            )

        soup = BeautifulSoup(response.content, 'html.parser')

        data = json.loads(response.text)
        df = pd.DataFrame(data)
        return

    
    def get_user_acces_token(self):

        # Try with the last user acces token
        if os.path.exists(FILE_USER_ACCES_TOKEN):
            with open(FILE_USER_ACCES_TOKEN, "rb") as f:
                self.user_acces_token = pickle.load(f)

        self.authorized_header = {
            'Authorization': f'Bearer {self.user_acces_token}'}
        if self.user_acces_token and self.test_user_acces_token():
            return



        """
        Problème : plus d'erreur génére donc on trouve pas le code
        """

        """html = self.session.get(
            f"{URL_SITE}oauth/authorize?client_id={self.client_id}"
            f"&response_type=code&redirect_uri=http://localhost/exchange_token&approval_prompt=force&"
            f"scope=read,read_all,profile:read_all,activity:read,activity:read_all")
            
        soup = BeautifulSoup(html.content, 'html.parser')
        playload = {
            'authenticity_token': soup.find('input', {'name': 'authenticity_token'})['value'],
            'read': '',
            'read_all': 'on',
            'profile:read_all': 'on',
            'activity:read': 'on',
            'activity:read_all': 'on'
        }"""

        """authentification_code = ''
        
        try:
            html = self.session.post(URL_SITE[:-1] + soup.find('form')['action'], playload)
        except requests.exceptions.ConnectionError as e:
            url = e.args[0].url
            codes = url.split('=')
            
            authentification_code = codes[(codes.index('&code') + 1)].split('&')[0]"""

        webbrowser.open(f"{URL_SITE}oauth/authorize?client_id={self.client_id}"
            f"&response_type=code&redirect_uri=http://localhost/exchange_token&approval_prompt=force&"
            f"scope=read,read_all,profile:read_all,activity:read,activity:read_all")

        authentification_code = input("Code : ")

               

        res = requests.post(
            f"https://www.strava.com/oauth/token?client_id={self.client_id}"
            f"&client_secret={self.client_secret}&code={authentification_code}"
            f"&grant_type=authorization_code")

        res = json.loads(res.text)

        self.user_acces_token = res["access_token"]
        self.authorized_header = {
            'Authorization': f'Bearer {self.user_acces_token}'
        }

        logging.debug('New user acces token : %s', self.user_acces_token)

        with open(FILE_USER_ACCES_TOKEN, "wb") as f:
            pickle.dump(self.user_acces_token, f)
            logging.debug('Succesful write user acces token.')

    def test_user_acces_token(self):

        if requests.get(URL_GET_USER_INFO, headers=self.authorized_header).status_code != 200:
            logging.debug('User acces token is wrong! Status code.')
            return False
        return True

    def get_user_info(self):

        html = requests.get(URL_GET_USER_INFO, headers=self.authorized_header)
        res = json.loads(html.text)
        created_at = res['created_at']
        created_at = created_at[:created_at.find('T')]

        self.created_at = created_at


if __name__ == "__main__":

    logging.basicConfig(level=logging.INFO)

    client = StravaClient()
    client.dowload_all_activities(download_all=True)
    #client.get_activity_stream(6481208309)
    # client.get_all_gpx(id_list)
