# Generated by Django 2.2.18 on 2021-03-14 17:30

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0016_auto_20210314_1447'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='listing',
            name='max_bid',
        ),
    ]
