from django.urls import path

from . import views


urlpatterns = [
    path("", views.index, name="index"),
    path("new_page/", views.new_page, name="new_page"),
    path("edit_page/<str:input_entry>/", views.edit_page, name="edit_page"),
    path("wiki/<str:input_entry>/", views.content, name="content"),
    path("wiki/random", views.random, name="random")
]
