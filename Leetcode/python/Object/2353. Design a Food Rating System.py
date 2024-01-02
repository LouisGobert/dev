import heapq
from collections import defaultdict
from dataclasses import dataclass
from heapq import heapify, heappush
from typing import Any, List, Tuple


@dataclass
class Food:
    rate: int
    food_name: str
    country: str

    def __eq__(self, other):
        return self.rate == other.rate and self.food_name == other.food_name

    def __gt__(self, other: "Food"):
        return self.rate > other.rate or (self.rate == other.rate and self.food_name > other.food_name)


class FoodRatings:
    food_by_country: dict[str, list[Food]]
    country_of_food: dict[str, str]
    map_food_to_rate: dict[str, int]

    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.food_by_country = defaultdict(list)
        self.country_of_food = {}
        self.map_food_to_rate = {}
        for food, cuisine, rating in zip(foods, cuisines, ratings):
            food_obj = Food(-rating, food, cuisine)
            heapq.heappush(self.food_by_country[cuisine], food_obj)
            self.country_of_food[food] = cuisine
            self.map_food_to_rate[food] = -rating

    def changeRating(self, food: str, newRating: int) -> None:
        country = self.country_of_food[food]
        self.map_food_to_rate[food] = -newRating
        heapq.heappush(self.food_by_country[country], Food(-newRating, food, country))

    def highestRated(self, cuisine: str) -> str:
        first_heap = self.food_by_country[cuisine][0]

        while self.map_food_to_rate[first_heap.food_name] != first_heap.rate:
            heapq.heappop(self.food_by_country[cuisine])
            first_heap = self.food_by_country[cuisine][0]
        return first_heap.food_name


if __name__ == "__main__":
    foods = ["pate", "coca", "redbull", "tomate", "ocqmvmwjq"]
    # [""],[""]]
    cuisines = ["belgique", "belgique", "belgique", "canada", "canada"]
    ratings = [2, 6, 18, 6, 5]

    obj = FoodRatings(foods, cuisines, ratings)
    obj.changeRating("redbull", 11)
    assert obj.highestRated("canada") == "tomate"
    obj.changeRating("pate", 3)
    obj.changeRating("coca", 9)
    obj.changeRating("pate", 14)
    assert obj.highestRated("canada") == "tomate"
    assert obj.highestRated("belgique") == "pate"
    # param_2 = obj.highestRated(cuisine)

    # ["FoodRatings","highestRated","changeRating","changeRating","highestRated","changeRating","highestRated","changeRating","changeRating","changeRating","changeRating","changeRating","changeRating","changeRating","highestRated","changeRating","highestRated"]
    foods = ["xxdcg", "wfqdeytt", "jqmfm", "ukqbjikyx", "aymciznrnw", "qhjjrvr", "wzcinxg", "ikxj"]
    cuisines = ["lruhtqy", "lruhtqy", "lruhtqy", "lruhtqy", "lruhtqy", "lruhtqy", "lruhtqy", "lruhtqy"]
    ratings = [8, 6, 1, 17, 20, 2, 17, 14]
    # [""],[],[],[""],["ukqbjikyx",10],["lruhtqy"],["xxdcg",11],["ikxj",15],["aymciznrnw",10],["wfqdeytt",10],["xxdcg",16],["ikxj",2],["aymciznrnw",16],["lruhtqy"],["wzcinxg",12],["lruhtqy"]]

    o = FoodRatings(foods, cuisines, ratings)
    assert o.highestRated("lruhtqy") == "aymciznrnw"
    o.changeRating("wfqdeytt", 17)
    o.changeRating("aymciznrnw", 9)
    assert o.highestRated("lruhtqy") == "ukqbjikyx"
