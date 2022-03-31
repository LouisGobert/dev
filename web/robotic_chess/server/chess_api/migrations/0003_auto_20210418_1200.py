# Generated by Django 2.2.18 on 2021-04-18 12:00

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('chess_api', '0002_board_squares'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='board',
            name='piece_left',
        ),
        migrations.AddField(
            model_name='board',
            name='computer_piece_remain',
            field=models.IntegerField(default=16),
        ),
        migrations.AddField(
            model_name='board',
            name='player_piece_remain',
            field=models.IntegerField(default=16),
        ),
        migrations.AddField(
            model_name='board',
            name='players',
            field=models.TextField(null=True),
        ),
    ]
