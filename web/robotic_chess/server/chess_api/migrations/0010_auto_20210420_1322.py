# Generated by Django 2.2.18 on 2021-04-20 13:22

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('chess_api', '0009_game_game_status'),
    ]

    operations = [
        migrations.AlterField(
            model_name='game',
            name='game_status',
            field=models.IntegerField(default=0),
        ),
    ]