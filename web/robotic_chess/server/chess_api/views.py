from django.shortcuts import render
from rest_framework import viewsets, serializers
from .models import Game
from django.http import HttpResponse, JsonResponse, HttpResponseRedirect
from django.urls import reverse
from django.core import serializers
from django.forms import ModelForm
from django import forms
import json
import logging
import logging.config
from .lib.const import *
from .lib.possibility import Possibility
from .lib.process import start
import sys
from .lib.action import *
from .lib.move import Move# Create your views here.
from copy import deepcopy

    
def new_game(request):

    # suppresion du Game actuelle
    Game.objects.all().delete()

    new_game = Game()
    board = INITIAL_BOARD
    new_game.board = json.dumps(board)
    new_game.game_status = GameStatus.PROGRESS
    new_game.player_piece_remain = 16
    new_game.computer_piece_remain = 16
    new_game.player_one_is_next = False
    new_game.save()


    return pull_game(request)


def pull_game(request):
    
    game = Game.objects.all().values()

    response = list(game)[0]

    response["board"] = json.loads(response["board"])
    response["previews"] = Possibility.all_possibility(response["board"], P_TWO)
    
    response = JsonResponse(response, safe=False)
    
    return RespondToJson(response)


def failed(request):
    response = JsonResponse({"game_status": GameStatus.FAILED}, safe=False)
    return RespondToJson(response)


def push_game(request):

    if request.method == "GET":

        try:
            move = Move()
            move.to_x = int(request.GET["to_x"])
            move.to_y = int(request.GET["to_y"])
            move.from_x = int(request.GET["from_x"])
            move.from_y = int(request.GET["from_y"])
            deep = int(request.GET["deep_search"])

            game = Game.objects.all()[:1].get()
            board = json.loads(game.board)

            

            
            Game.print_board(board)
            #print("\nDéplacement vers :", move)
            if not deplacement(move, game, board):
                Game.print_board(board)

                move = start(deepcopy(board), deepcopy(game), deep)
                deplacement(move, game, board)



            # sauvegarde
            game.board = json.dumps(board)
            game.save()


            if game.game_status == GameStatus.PROGRESS:
                previews = Possibility.all_possibility(board, P_TWO)


            else:
                previews = None
            
            from_x, from_y, to_x, to_y = move.extract()
            response = JsonResponse({      
                "game_status": game.game_status,
                "previews": previews,
                "from_x": from_x,
                "from_y": from_y,
                "to_x": to_x,
                "to_y": to_y,
                "piece_player_one": game.piece_player_one,
                "piece_player_two": game.piece_player_two,
            } , safe=False) 
            
            
            return RespondToJson(response)

        except:
            print("Erreur :", sys.exc_info()[0])
            print(sys.exc_info())
            
    return failed(request)
    

def RespondToJson(response):
    """
    Permet d'ajouté le Access-Control-Allow-Origin a chaque réponse
    """
    response["Access-Control-Allow-Origin"] = "*"
    return response
