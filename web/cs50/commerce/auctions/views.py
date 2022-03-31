from django.contrib.auth import authenticate, login, logout
from django.db import IntegrityError
from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from django.urls import reverse
from django.shortcuts import redirect
from .models import Listing, Categorie, User
from django.contrib.auth.decorators import login_required
from django import forms
from django.core.validators import MinValueValidator
from .models import User, NewListingForm
from django.forms import ModelForm
from django.contrib import messages 


def index(request):
    return render(request, "auctions/index.html", {
        "listings": Listing.objects.all().order_by("date")
    })


def login_view(request):
    if request.method == "POST":

        # Attempt to sign user in
        username = request.POST["username"]
        password = request.POST["password"]
        user = authenticate(request, username=username, password=password)

        # Check if authentication successful
        if user is not None:
            login(request, user)
            return HttpResponseRedirect(reverse("index"))
        else:
            return render(request, "auctions/login.html", {
                "message": "Invalid username and/or password."
            })
    else:
        return render(request, "auctions/login.html")


def logout_view(request):
    logout(request)
    return HttpResponseRedirect(reverse("index"))


def register(request):
    if request.method == "POST":
        username = request.POST["username"]
        email = request.POST["email"]

        # Ensure password matches confirmation
        password = request.POST["password"]
        confirmation = request.POST["confirmation"]
        if password != confirmation:
            return render(request, "auctions/register.html", {
                "message": "Passwords must match."
            })

        # Attempt to create new user
        try:
            user = User.objects.create_user(username, email, password)
            user.save()
        except IntegrityError:
            return render(request, "auctions/register.html", {
                "message": "Username already taken."
            })
        login(request, user)
        return HttpResponseRedirect(reverse("index"))
    else:
        return render(request, "auctions/register.html")


def listing(request, listing_id):

    try:
        listing = Listing.objects.get(pk=listing_id)

        # POST view
        if request.method == "POST":
            if "delete" in request.POST:
                listing.delete()
                return HttpResponseRedirect(reverse("index"))

            elif "delete_from_watchlist" in request.POST:
                user = User.objects.get(pk=request.user.id)
                user.watchlist.remove(listing)
                
            elif "add_to_watchlist" in request.POST:
                user = User.objects.get(pk=request.user.id)
                user.watchlist.add(listing)
            
            return HttpResponseRedirect(reverse("listing", args=[listing_id]))



        # Normal view

        is_watchlisted = False
        if request.user.is_authenticated:

            try:
                user = User.objects.get(pk=request.user.id).watchlist.get(pk=listing_id)
                #user.watchlist.get(pk=listing_id)
                is_watchlisted = True
            except:
                is_watchlisted = False

    

        return render(request, "auctions/listing.html", {
        "listing": listing,
        "is_watchlisted": is_watchlisted
        })
    
    except Listing.DoesNotExist:
        return redirect(reverse("404"))


    


def not_found(request):
    return render(request, "auctions/404.html")


def categories(request):
    return render(request, "auctions/categories.html", {
        "categories": Categorie.objects.all()
    })

def display_categorie(request, cat_id):
    return render(request, "auctions/display_categorie.html", {
        "cat": cat_id,
        "listings": Listing.objects.filter(categorie=cat_id)
    })

@login_required
def create_listing(request):

    if request.method == "POST":
        form = NewListingForm(request.POST, request.FILES)
    
        #check the validity
        if form.is_valid():

            try:
                new_listing = Listing(
                author=request.user,
                title=form.cleaned_data['title'], 
                description=form.cleaned_data['description'], 
                starting_price=form.cleaned_data['starting_price'],
                categorie=form.cleaned_data['categorie'],
                img=request.FILES['img'])
            except:

                new_listing = Listing(
                author=request.user,
                title=form.cleaned_data['title'], 
                description=form.cleaned_data['description'], 
                starting_price=form.cleaned_data['starting_price'],
                categorie=form.cleaned_data['categorie'])

            new_listing.save()

            return HttpResponseRedirect(reverse("listing", args=[new_listing.pk]))

        else:
            pass



    return render(request, "auctions/create_listing.html", {
        "form": NewListingForm()
    })


