from django.urls import path

from . import views

urlpatterns = [
    path("new_game", views.new_game, name="new_game"),
    path("pull_game", views.pull_game, name="pull_game"),
    path("push_game", views.push_game, name="push_game"),
]
