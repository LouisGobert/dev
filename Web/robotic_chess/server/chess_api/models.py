from django.db import models
from .lib.const import *

# Create your models here.

class Game(models.Model):
    piece_player_one = models.IntegerField(default=16)
    piece_player_two = models.IntegerField(default=16)
    game_status = models.IntegerField(default=0)

    player_one_is_next = models.BooleanField(default=True)

    board = models.TextField(null=True)


    @staticmethod
    def print_board(board):
        for y in range(8):
            for x in range(8):
                if board[y][x]:

                    player = "One" if board[y][x][1] == P_ONE else "TWO"
                    print("[{} : {}]".format(board[y][x][0], player), end='')
                else:
                    print("[       ]", end='')

            print('')
