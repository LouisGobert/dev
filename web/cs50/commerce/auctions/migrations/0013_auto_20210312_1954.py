# Generated by Django 2.2.18 on 2021-03-12 19:54

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0012_auto_20210312_1953'),
    ]

    operations = [
        migrations.AlterField(
            model_name='listing',
            name='description',
            field=models.CharField(max_length=1024, unique=True),
        ),
    ]
