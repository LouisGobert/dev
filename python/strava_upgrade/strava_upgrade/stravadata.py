#!/usr/bin/env python
# coding: utf-8

import pandas as pd
import config
import utils
import logging

def cheat_speed(activity, force_keep=True):
    """
    
    Remove or try to set a correct speed if the current
    speed is detect to be cheat or be an error.

    return empty activity if calculated speed is over limit.

    """

    # No speed limit
    if activity['type'] not in config.MAX_SPEED:
        return activity


    MAX_SPEED = config.MAX_SPEED[activity['type']]
    
    if activity['average_speed'] > MAX_SPEED:
        new_speed = activity['distance'] / (activity['elapsed_time'] / 60)

        if not force_keep and new_speed > MAX_SPEED:
            return pd.DataFrame()

        activity['average_speed'] = round(new_speed, 4)

    if activity['max_speed'] > MAX_SPEED:
        activity['max_speed'] = activity['average_speed']
    
    return activity


def keep_good_columns(df):
    """

    This function keep only good data from df

    """

    return df.loc[:,[
        'id',
        'type',
        'distance',
        'moving_time',
        'total_elevation_gain',
        'date',
        'average_speed',
        'max_speed'
    ]]


def convert_unit(activity):
    """
    
        - convert average_speed from m/s to km/h
        - convert max_speed from m/s to km/h
        - convert moving_time in seconde to minutes
    
    """
    activity['average_speed'] = activity['average_speed'] * 3.6
    activity['max_speed'] = activity['max_speed'] * 3.6
    activity['distance'] = activity['distance'] / 1000
    activity['moving_time'] = activity['moving_time'] // 60
    activity['elapsed_time'] = activity['elapsed_time'] // 60

    #return activity

def data_processing(df):
    """
    
    Function who process data before store it:
        - set index to id
        - remove useless data
        - remove activity which max_speed is zero --> manually added
        - rename activity type

    """
    ACTIVITY_TYPE = {
        'Run' : 'run',
        'Ride': 'ride',
        'EBikeRide': 'e_ride',
        'Workout': 'workout',
        'RockClimbing': 'rock_climbing',
        'Hike': 'hike',
        'VirtualRide': 'virtual_ride',
        'Swim': 'swim'
    }

    for i, row in df.iterrows():
        
        convert_unit(row)
        row['type'] = ACTIVITY_TYPE[row['type']]

        row = cheat_speed(row)
        if row is None:
            df.drop(i, axis=0)
        else:
            df.iloc[i] = row


    
    df.rename(columns={'start_date_local': 'date'}, inplace=True)
    df = keep_good_columns(df)

    logging.debug("Data processing performed")
    return df


def force_data_processing():
    df_activities = utils.read_json_to_df(config.ACTIVITIES_JSON)
    df_activities =  data_processing(df_activities)
    utils.write_df_to_json(df_activities, config.ACTIVITIES_JSON)



def period_group(df_activities, activity_type, period):
	"""
	
	Il faut faire attention a ne pas laisser un écart période dans les activités. 
	
	"""

	period_available = pd.to_datetime(df_activities['date'].dt.to_period('M'))[df_activities.type == activity_type]
	#month_all = pd.date_range(month_available.iloc[-1].strftime('%Y-%m'), '2022-01-01', freq='1MS').to_period('M')
	all_period = pd.period_range(period_available.iloc[-1], period_available.iloc[0], freq=period)
	df_groupby = df_activities.groupby(period_available)

	df_period = df_groupby.sum(numeric_only=True)
	df_period['period'] = df_period.index.astype(str)
	df_period['average_speed'] = df_groupby['average_speed'].mean()
	df_period['max_speed'] = df_groupby['max_speed'].max()


	past_average_speed = None
	for m in all_period:
		if m not in df_period['period']:
			df_period.loc[m] = 0
			df_period.at[m, 'period'] = m.strftime('%Y-%m')
			if past_average_speed:
				df_period.at[m, 'average_speed'] = past_average_speed
		else:
			past_average_speed = df_period.at[m, 'average_speed']


	df_period = df_period.sort_values(by='period')


	return df_period


if __name__ == "__main__":
    #force_data_processing()
    df_activities = utils.read_json_to_df(config.ACTIVITIES_JSON)
    
