#!/usr/bin/env python
# coding: utf-8
"""

TODO:
	-	Highlight line when over it
	- X label like '2020 October'
	- Y hight not good adapted


"""

__author__ = 'Gobert Louis'

import pandas as pd
import stravadata as sd
import stravaclient as sc
import utils
import config

from bokeh.io import output_file
from bokeh.plotting import figure, show
from bokeh.layouts import column, gridplot, layout, row
from bokeh.models import HoverTool, ColumnDataSource, Plot, VBar, LinearAxis, Grid, ColorPicker, DatetimeTickFormatter, PanTool, Range1d, Title, Slider
from bokeh.colors import RGB
from bokeh.palettes import Colorblind4


def print_activities_stats(df_activities):
	"""
	
	Function who print different stats of the number of activity / type ...


	TODO:
		- Total time per activity
		- Total distance per acivity
		- Activity per country
	
	"""
	print(f'Activities info : \n'
		  f'	{df_activities.groupby("type").size()}')
		
		


def render_stats(df_activities, created_at='2017-12'):
	"""
	
	Function who show a graphic with different activity
	statis with line.

	TODO:
		-	Label of "elevation gain" is not the same then the
			label Km
	
	"""

	# W for week
	# D for day
	# M for month
	PERIOD = 'M'
	ACTIVITY_TO_SHOW = [
		'run',
		'ride',
		'e_ride',
		'hike',
	]


	max_distance = 0
	max_elevation = 0
	max_time = 0
	max_speed = 0
	data = []
	for activity in ACTIVITY_TO_SHOW:
		data.append(ColumnDataSource(sd.period_group(df_activities, activity, PERIOD)))
		max_distance = max(data[-1].data['distance'].max(), max_distance)
		max_elevation = max(data[-1].data['total_elevation_gain'].max(), max_elevation)
		max_time = max(data[-1].data['moving_time'].max(), max_time)
		max_speed = max(data[-1].data['average_speed'].max(), max_speed)


	hover_tool = HoverTool(tooltips=[
		("Date ", "@period"), 
		("Distance ", "@distance km kilometters"),
		("Elevation gain ", "@total_elevation_gain metters"),
		("Moving time ", "@moving_time minutes"),
		("Avrerage speed ", "@average_speed km/h"),
	])

	x_range = list(map(str,pd.period_range(created_at, '2022-01-04', freq=PERIOD)))
	y_range = (0, max_distance + (max_distance//20))
	fig = figure(
		x_range=x_range,
		y_range=y_range,
		title="Run and ride stats", 
		x_axis_label='Date', 
		y_axis_label='Distance',
		tools="xwheel_zoom,reset,save",
		output_backend="webgl",
		active_scroll='xwheel_zoom',
		toolbar_location="above"
	)
	
	fig.add_tools(hover_tool)
	fig.add_tools(PanTool(dimensions="width"))
	fig.toolbar.logo = None
	fig.toolbar.autohide = True
	fig.xaxis.major_label_orientation = 1
	fig.sizing_mode = 'stretch_width'
	fig.height = 800

	# The other catgegorie 
	fig.extra_y_ranges = {
		"elev_gain": Range1d(start=0, end=max_elevation + (max_elevation // 20)),
		"moving_time": Range1d(start=0, end=max_time + (max_time // 20)),
		"average_speed": Range1d(start=0, end=max_speed + (max_speed // 20))

	}

	fig.add_layout(LinearAxis(y_range_name='elev_gain'), 'right')
	fig.add_layout(Title(text='Elevation gain', vertical_align='top', align='center'), 'right')
	fig.add_layout(LinearAxis(y_range_name='moving_time'), 'right')
	fig.add_layout(Title(text='Moving time', vertical_align='top', align='center'), 'right')
	fig.add_layout(LinearAxis(y_range_name='average_speed'), 'right')
	fig.add_layout(Title(text='Average speed', vertical_align='top', align='center'), 'right')

	colors_pickers = []
	sliders = []
	LINE_WIDTH = 2.5

	elevation_gain_label = ['D+ ' + ACTIVITY_TO_SHOW[i]  for i in range(len(ACTIVITY_TO_SHOW))]
	time_label = ['Time ' + ACTIVITY_TO_SHOW[i]  for i in range(len(ACTIVITY_TO_SHOW))]

	for data, label, color, elevation_gain_label, time_label in zip(data, ACTIVITY_TO_SHOW, Colorblind4, elevation_gain_label, time_label):

		distance_line = fig.line(
			x='period', 
			y='distance', 
			source=data,  
			legend_label=label + ' distance',  
			color=color, 
			line_width=LINE_WIDTH
		)

		elevation_gain_line = fig.line(
			x='period', 
			y='total_elevation_gain', 
			source=data,  
			legend_label=label + ' elevation',  
			color=color, 
			line_width=LINE_WIDTH,
			line_dash='dashed',
			y_range_name='elev_gain'
		)

		moving_time_line = fig.line(
			x='period', 
			y='moving_time', 
			source=data,  
			legend_label=label + ' time',  
			color=color, 
			line_width=LINE_WIDTH,
			line_dash='dashdot',
			y_range_name='moving_time'
		)

		average_speed_line = fig.line(
			x='period', 
			y='average_speed', 
			source=data,  
			legend_label=label + ' average speed',  
			color=color, 
			line_width=LINE_WIDTH,
			line_dash='dotdash',
			y_range_name='average_speed')

		new_color_picker = ColorPicker(title=f"Color for {label.lower()} line", color=color, max_height=100)
		new_color_picker.js_link('color', distance_line.glyph, 'line_color')
		new_color_picker.js_link('color', elevation_gain_line.glyph, 'line_color')
		new_color_picker.js_link('color', moving_time_line.glyph, 'line_color')
		new_color_picker.js_link('color', average_speed_line.glyph, 'line_color')
		colors_pickers.append(new_color_picker)

		new_slider = Slider(start=0.01, end=10, step=0.01, value=LINE_WIDTH, max_height=30)
		new_slider.js_link('value', distance_line.glyph, 'line_width')
		sliders.append(new_slider)

	fig.legend.click_policy="hide"
	fig.legend.location="top_left"

	grid = layout([
		[fig],
		colors_pickers,
		sliders],
		sizing_mode='stretch_both')


	output_file(config.OUTPUT_FILE)
	show(grid)


if __name__ == "__main__":
	user = stravaclient.StravaClient()
	df_activities = utils.read_json_to_df(config.ACTIVITIES_JSON)
	render_stats(df_activities)





