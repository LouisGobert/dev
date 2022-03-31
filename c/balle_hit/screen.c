#include "screen.h"

/*
 * Fonction qui affiche toutes les casse ainsi que
 * le slider et la belle a l'écran.
 *
 * ren 			: le renderer
 * rect			: la liste des casses a afficher ainsi que le slider et la balle
 * game			: les infos du jeux en cours
 * start_game	: les infos du jeux de basse
*/
void render(SDL_Renderer *ren, SDL_Rect *rect, bool *game, bool *start_game) {
	SDL_SetRenderDrawColor(ren, RED_R, RED_G, RED_B, TRANSPARANCE);
	SDL_RenderClear(ren);

	int pos = 0;
	for (int i = 0; i < NB_CASE; i++) {
		if (game[i]) {
			(!(i % 2)) ? 
				  SDL_SetRenderDrawColor(ren, GREY_R, GREY_G, GREY_B, TRANSPARANCE) 
				: SDL_SetRenderDrawColor(ren, WHITE_GREY_R, WHITE_GREY_G, WHITE_GREY_B, TRANSPARANCE);

			SDL_RenderFillRect(ren, &rect[pos]);
			pos++;
		}
		else if (start_game[i])	pos++;
		
		
	}
	SDL_SetRenderDrawColor(ren, BLACK_R, BLACK_G, BLACK_B, TRANSPARANCE);

	// Affichage de la balle
	SDL_RenderFillRect(ren, &rect[pos]);
	// Affichage du slider
	pos++;
	SDL_RenderFillRect(ren, &rect[pos]);


	SDL_RenderPresent(ren);
}
