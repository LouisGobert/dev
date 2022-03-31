from django.shortcuts import render
from django import forms
from markdown2 import markdown
from django.urls import reverse
from django.http import HttpResponseRedirect
from django.shortcuts import redirect
from random import sample
from . import util


class NewPageForm(forms.Form):
    title = forms.CharField(label="Title")
    content = forms.CharField(widget=forms.Textarea(attrs={'cols': 1, 'rows': 2}))
    

def index(request):
    if request.method == "POST":

        try:
            # Match 
            entry = util.get_entry(request.POST['q'])
            if entry is not None:
                # redirect to entry pages
                return redirect(reverse("content", args=[request.POST['q']]))

            # try to find a substring with the search input
            entries = util.list_entries()
            entries = [ele for ele in entries if request.POST['q'] in ele]
            
            # A substring is found
            return render(request, "encyclopedia/index.html", {
                "entries": entries
            })

        # Error in POST method
        except:
            return render(request, "encyclopedia/index.html", {
                "entries": None
            })


    # Default index
    return render(request, "encyclopedia/index.html", {
        "entries": util.list_entries()
    })


def content(request, input_entry):
    
    entry = util.get_entry(input_entry)
    if entry != None:
        entry = markdown(entry)

    return render(request, "encyclopedia/content.html", {
        "entry": entry,
        "input_entry": input_entry
    })

def new_page(request):
    # Add new page
    if request.method == "POST":
        form = NewPageForm(request.POST)

        # Check the validity
        if form.is_valid():
            title = form.cleaned_data["title"]
            content = form.cleaned_data["content"]

            # Succesfull, adding page
            if util.get_entry(title) is None:
                util.save_entry(title, content)
                return redirect(reverse("content", args=[title]))

            else:
                # A page with the same title is detect
                return render(request, "encyclopedia/new_page.html", {
                "title_exist": True,    
                "form": form
            })
        # Not valid data
        else:
            return render(request, "encyclopedia/new_page.html", {
                "title_exist": False,
                "form": form
            })

    # Default new_page
    return render(request, "encyclopedia/new_page.html", {
        "title_exist": False,
        "form": NewPageForm()
    })



def random(request):
    return redirect(reverse("content", args=[sample(util.list_entries(), 1)[0]]))


def edit_page(request, input_entry):

    if request.method == "POST":

        try:
            # Get the content and title and save it
            content = request.POST['content']
            title = request.POST['title']

            # The title is modified and the name page don't exist
            # no error information display
            if util.get_entry(title) is None:
                return redirect(reverse("index"))

            util.save_entry(title, content)
            content = markdown(content)

            # return to entry pas
            return redirect(reverse("content", args=[title]))
 
        except:
            # No error info display because not specified in specification
            return redirect(reverse("index"))


    return render(request, "encyclopedia/edit_page.html", {
        "input_entry": input_entry,
        "content": util.get_entry(input_entry)
    })