#!/usr/bin/env python3
# coding: utf-8

import gpxpy
import os
import glob
import pickle
import webbrowser


OUTPUT_DIR = 'output/index.html'

def gen_with_polylines_file(polylines_file):
    if os.path.exists(polylines_file):

        with open(polylines_file, 'r') as f:
            polylines = f.read()

            OUTPUT_DIR = 'test/test_gpx_generated.html'
            generate_html(polylines)



def gen_with_multiple_polyline(polylines, output_dir=OUTPUT_DIR):

    print('Generate with polylines')

    generate_html(polylines, output_dir)
    webbrowser.open(output_dir)




def gen_with_gpx_folder(gpx_folder) -> None:



    if os.path.exists(gpx_folder):

        gpx_list = []
        gpx_file_list = glob.glob(f'{gpx_folder}/*.gpx')

        length = len(gpx_file_list)

        for i in range(length):
            gpx_list.append((gpx_to_polyline(gpx_file_list[i])))

            print(f'{i}/{length} loads. - gpx_file.length = {len(gpx_list)}')
            
        if(gpx_list):
            generate_html(gpx_list)
            
            print("Done generating html page: ", OUTPUT_DIR)
            webbrowser.open(OUTPUT_DIR)
    else:
        print('Path not found : ', gpx_folder)


def gpx_to_polyline(filename: str):

    trackPoints: list = []

    if not os.path.exists(filename):
        print(f"File not found: {filename}")
        return

    with open(filename) as gpx_file:

        if '<?xml version="1.0" encoding="UTF-8"?>' in gpx_file.readline():
        
            last_lat_lng = [0,0]

            try:
                gpx = gpxpy.parse(gpx_file)
                for track in gpx.tracks:
                    for segment in track.segments:
                        for point in segment.points:

                            lat_lng = [round(point.latitude, 5), round(point.longitude, 5)]

                            if last_lat_lng != lat_lng:
                                trackPoints.append(lat_lng)
                                last_lat_lng = lat_lng


            except Exception as error:
                print(f"\nParsing file '{filename}' failed. Error: {error}")
    
        else:
            print(f'File : {filename} is not GPX.')
    return trackPoints


def generate_html(polyline_list: list, output_dir=OUTPUT_DIR) -> None:
    """Generates a new html file with points"""

    template = ''

    with open('src/template/template.html', 'r') as f:
        template = f.read()


    polyline_list_str = f'var gpx_list={polyline_list};'    

    #track_points = f"var track=[{gpx_list}];"
    template = template.replace("var gpx_list = [];", polyline_list_str)


    with open(output_dir, 'w') as f:
        f.write(template)
        print('File generated in ', output_dir)

if __name__ == '__main__':
    gen_with_gpx_folder('test/gpx')

