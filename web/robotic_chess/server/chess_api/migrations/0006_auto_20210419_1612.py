# Generated by Django 2.2.18 on 2021-04-19 16:12

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('chess_api', '0005_auto_20210419_1326'),
    ]

    operations = [
        migrations.RenameField(
            model_name='game',
            old_name='player_is_next',
            new_name='player_one_is_next',
        ),
    ]