#!/usr/bin/env python
# coding: utf-8

from xmlrpc.client import Boolean
import pandas as pd
import os
import logging

def read_json_to_df(src) ->  pd.DataFrame:
    """
    Function who open src/activities.json and return it or -1 if error
    """

    if os.path.exists(src):
        try:
            activities = pd.read_json(src)
            return activities
        except IOError:
            logging.error(f'File {src} doesnt exist')
        except ValueError:
            logging.error(f'Bad value/format when reading {src}')
    else:
        logging.error(f'File {src} not exists.')

    return pd.DataFrame()


def write_df_to_json(df, dest) -> Boolean:
    df.to_json(dest, indent=4)
    logging.info('Dataframe write in %s', dest)
