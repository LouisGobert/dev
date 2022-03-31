#!/usr/bin/env python
# coding: utf-8

import unittest
from unittest.mock import patch
import pandas as pd
import sys


sys.path.insert(0, '/home/louis/Documents/dev/python/strava_upgrade/strava_upgrade')
import stravadata

class TestStravaData(unittest.TestCase):

    def __init__(self, *args, **kwargs):
        super(TestStravaData, self).__init__(*args, **kwargs)

        self.data_over_aver_speed_uncal = pd.DataFrame({
            'id': [0],
            'date': ['2022-01-24T16:17:47Z'],
            'average_speed': [147],
            'max_speed': [12],
            'type': ['run'],
            'distance':[ 4.45],
            'elapsed_time': [1]}).iloc[0]

        self.data_over_aver_speed_cal = pd.DataFrame({
            'id': [0],
            'date': ['2022-01-24T16:17:47Z'],
            'average_speed': [147],
            'max_speed': [12],
            'type': ['run'],
            'distance':[ 4.45],
            'elapsed_time': [53]}).iloc[0]


    def test_cheat_speed_over_aver_speed_notcalc(self):
        
        result = stravadata.cheat_speed(self.data_over_aver_speed_uncal, False)
        self.assertTrue(result.empty)


    def test_cheat_speed_over_aver_speed_calc(self):
        result = stravadata.cheat_speed(self.data_over_aver_speed_cal, False)

        corrected_data = pd.DataFrame({
            'id': [0],
            'date': ['2022-01-24T16:17:47Z'],
            'average_speed': [5.0377],
            'max_speed': [12],
            'type': ['run'],
            'distance':[ 4.45],
            'elapsed_time': [53]}).iloc[0]

        self.assertTrue((result == corrected_data).all())
        

if __name__ == '__main__':
    unittest.main()
