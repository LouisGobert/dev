from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("login", views.login_view, name="login"),
    path("logout", views.logout_view, name="logout"),
    path("register", views.register, name="register"),
    path("listing/<str:listing_id>", views.listing, name="listing"),
    path("404", views.not_found, name="404"),
    path("categories", views.categories, name="categories"),
    path("categories/<int:cat_id>", views.display_categorie, name="display_categorie"),
    path("create_listing", views.create_listing, name="create_listing")
    

]
