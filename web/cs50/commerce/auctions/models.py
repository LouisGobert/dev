from django.contrib.auth.models import AbstractUser
from django.core.validators import MinValueValidator
from django.db import models
from django.utils import timezone
from django.utils.html import mark_safe
from django.db.models import Max
from django.forms import ModelForm, Textarea, DecimalField, ValidationError



class User(AbstractUser):
    watchlist = models.ManyToManyField("Listing", blank=True)

    @property
    def count_watchlist(self):
        return self.watchlist.count()


    


class Categorie(models.Model):
    categorie = models.CharField(max_length=64)

    def __str__(self):
        return f"{self.categorie}"





class Listing(models.Model):
    author = models.ForeignKey(User, on_delete=models.CASCADE)
    title = models.CharField(max_length=64)
    description = models.CharField(max_length=1024, unique=True)#unique constraint
    starting_price = models.DecimalField(validators=[MinValueValidator(0)], decimal_places=2, max_digits=10)
    categorie = models.ForeignKey(Categorie, on_delete=models.SET_NULL, null=True, blank=True)
    img = models.ImageField(upload_to="img_folder/", blank=True, verbose_name="Image", null=True)
    date  = models.DateTimeField(default=timezone.now, blank=True)

    def __str__(self):
        return f"{self.title} from {self.author}"

    @property
    def get_price(self):
        query = Bid.objects.filter(listing = self.pk).aggregate(Max('price'))
        if query['price__max'] is None:
            return self.starting_price
        else:
            return query['price__max']







class NewListingForm(ModelForm):

    starting_price = DecimalField(min_value=0, decimal_places=2, max_value=99999999)


    class Meta:
        model = Listing
        fields = ['title', 'description', 'starting_price', 'categorie', 'img']
        widgets = {
            'description': Textarea(attrs={'cols': 80, 'rows': 20}),
        }

       
    




class Bid(models.Model):
    price = models.DecimalField(validators=[MinValueValidator(0)], decimal_places=2, max_digits=10)
    date  = models.DateTimeField(default=timezone.now)
    user = models.ForeignKey(User, on_delete=models.CASCADE)
    listing = models.ForeignKey(Listing, on_delete=models.CASCADE)

    def __str__(self):
        return f"{self.price}"

   
   

