#!/usr/bin/env python
# coding: utf-8
from setuptools import setup

setup(
    name='strava_upgrade',
    version="0.1.0",
    author='Louis Gobert',
    author_email='louis.gobert@gmail.com',
    packages=['strava_upgrade', 'strava_upgrade.tests'],
    description='Strava Upgrade',
    long_description=open('README.md').read(),
)

