# Generated by Django 2.2.18 on 2021-03-23 18:45

from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0017_remove_listing_max_bid'),
    ]

    operations = [
        migrations.AlterField(
            model_name='listing',
            name='categorie',
            field=models.ForeignKey(blank=True, null=True, on_delete=django.db.models.deletion.SET_NULL, to='auctions.Categorie'),
        ),
        migrations.AlterField(
            model_name='listing',
            name='img',
            field=models.ImageField(blank=True, null=True, upload_to='img_folder/', verbose_name='Image'),
        ),
    ]
