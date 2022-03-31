from django.contrib import admin
from .models import User, Listing, Bid, Categorie

# Register your models here.

class UserAdmin(admin.ModelAdmin):
    list_display = ("username", "get_products",)

    def get_products(self, obj):
        return "\n".join([str(p) for p in obj.watchlist.all()])

    get_products.short_description = "Watchlist"



class ListingAdmin(admin.ModelAdmin):
    list_display = ("author", "title", "description", "starting_price", "max_bid", "categorie", "date")

    ordering= ("date",)
    def max_bid(self, obj):
        max_bid = 0
        try:
            max_bid = Bid.objects.filter(listing=obj).order_by("-price")[0]
        except:
            return None

        return max_bid


class BidAmdin(admin.ModelAdmin):
    list_display = ("user", "listing","price","date")
   


class CategorieAdmin(admin.ModelAdmin):
    list_display = ("categorie",)



admin.site.register(User, UserAdmin)
admin.site.register(Listing, ListingAdmin)
admin.site.register(Bid, BidAmdin)
admin.site.register(Categorie, CategorieAdmin)
