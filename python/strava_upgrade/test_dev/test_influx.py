from datetime import datetime
import pandas as pd

from influxdb_client import InfluxDBClient, Point, WritePrecision
from influxdb_client.client.write_api import SYNCHRONOUS

# You can generate an API token from the "API Tokens Tab" in the UI
token = "sZ2ZVFXnDzWz99bnfK399pbprvThxVmy1qoB-C5hkwnrEkTlBUNIj48_0Vq8MBlXMv1keHYtvAgqPrBrMAlcfQ=="
org = "strava_upgrade"
bucket = "distance"

with InfluxDBClient(url="http://localhost:8086", token=token, org=org) as client:
    csv_df = pd.read_json('output/json/activities.json')

    write_api = client.write_api(write_options=SYNCHRONOUS)

    for i in csv_df.index:

        #date = str(csv_df['date'][i])
        #date = date.split(' ')[0]
        #date = datetime.strptime(date, '%d/%m/%Y')


        point = Point(csv_df['type'][i]) \
        .field("distance", csv_df['distance'][i]) \
        .field("elevation", csv_df['total_elevation_gain'][i]) \
        .field("average_speed", csv_df['average_speed'][i]) \
        .field("max_speed", csv_df['max_speed'][i]) \
        .field("moving_time", csv_df['moving_time'][i]) \
        .time(csv_df['date'][i].to_pydatetime(), WritePrecision.NS)

        write_api.write(bucket, org, point)
