# Generated by Django 2.2.18 on 2021-03-12 19:55

import datetime
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0013_auto_20210312_1954'),
    ]

    operations = [
        migrations.AddField(
            model_name='listing',
            name='date',
            field=models.DateTimeField(blank=True, default=datetime.datetime.now),
        ),
    ]