#include "collide.h"

bool sliderCollide(double* x_move, double* y_move, SDL_Rect* rect, int nb_rect) {
	//-------------------------------------------------------------------------//
	//																		   //
	//								SLIDER COLLIDE							   //
	//																		   //
	//-------------------------------------------------------------------------//	
	int index_bal = nb_rect-2, index_slider = nb_rect-1;

	if (SDL_HasIntersection(&rect[index_slider], &rect[index_bal])) {
		//
		// A AMELIORER
		//
		rect[index_bal].y = (SCREEN_HEIGHT - (2 * SLIDER_H)) - BAL_H - 1;


		// On obtient la distance entre d�but slider et impact
		// Dist varie de -57 � + 57
		// Si dist est a 0, la balle remonte en ligne droite
		double dist = ((rect[index_bal].x + BAL_W / 2) - rect[index_slider].x) - SLIDER_W / 2;

		// On affecte le nouvelle angle a x
		*x_move = (dist==0) ? 0 : (dist / 57) * 15;


		// Simple inversion de la hauteur
		*y_move -= 2 * *y_move;

		// Returne true car collision
		return true;
	}
	return false;
}

bool boardCollide(double* x_move, double* y_move, SDL_Rect* rect, int nb_rect) {
	bool collide = false;
	// Rebond sur top du jeux
	if (rect[nb_rect-2].y < 0) {
		*y_move -= 2 * *y_move;
		collide = true;
	}
	// Rebond sur cot� gauche ou droite
	else if (rect[nb_rect - 2].x > SCREEN_WIDTH - BAL_W || rect[nb_rect - 2].x < 0) {
		// Rebondi sur les cot�s
		*x_move -= 2 * *x_move;
		collide = true;
	}
	return collide;
}



int rectCollide(double* x_move, double* y_move, bool *game, SDL_Rect* rect, int nb_rect, bool *start_game, int nb_block) {
	SDL_Rect collision;
	int pos = 0;
	for (int i = 0; i < NB_CASE; i++) {
		if (game[i] && SDL_IntersectRect(&rect[nb_rect - 2], &rect[pos], &collision)) {

			rect[nb_rect-2].x -= *x_move + collision.h;
			rect[nb_rect-2].y -= *y_move + collision.w;
			// On supprime la casse du jeux
			game[i] = false;
				
			nb_block--; // On retire 1 du nombre de block
			
				
			// On regarde ou la bal touche un rectangle
			// On touche par dessous ou par dessus
			if (collision.w > collision.h) *y_move -= 2 * *y_move;
			else *x_move -= 2 * *x_move;

		
			pos++;
			i = NB_CASE; // On stop la boucle
		}
		else if (start_game[i] || game[i])	pos++;
	}

	return nb_block; // Le nombre de block encore jouable
}
