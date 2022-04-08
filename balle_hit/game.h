#include "main.h"

int initGame(bool* game, bool* start_game, FILE* log);
int moveBal(double* x_move, double* y_move, bool* game, SDL_Rect* rect, int nb_rect, bool* start_game, int nb_block);
void speedUpdate(double* x_move, double* y_move);