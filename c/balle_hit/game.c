#include "game.h"

int moveBal(double *x_move, double *y_move, bool *game, SDL_Rect *rect, int nb_rect, bool *start_game, int nb_block) {


	// Si interesction avec slider
	bool collide = false;
	int index_bal = nb_rect - 2;

	rect[index_bal].x += *x_move;
	rect[index_bal].y += *y_move;
	speedUpdate(x_move, y_move);

	/*
	 *Test de collision entre les rectangles si dans la zone de jeux
	 *
	 * Test de collision avec le slider si dans la zone de slider
	 */

	// Si la balle est dans la zone de jeux
	if (rect[index_bal].y > SCREEN_HEIGHT)
		return 0;
	if (!collide && rect[index_bal].y + 15 > SCREEN_HEIGHT - (2 * SLIDER_H) - 1)
		collide = sliderCollide(x_move, y_move, rect, nb_rect);
	if (!collide)
		collide = boardCollide(x_move, y_move, rect, nb_rect);
	if (rect[index_bal].y <= (RECTY * RECTH)) 
		nb_block = rectCollide(x_move, y_move, game, rect, nb_rect, start_game, nb_block);
	

	/*
		INVERSER L ORDRE DE CALCULC DE MOVE DE LA BALLE
	*/
	// On fait se déplacer la balle

	
	return nb_block;
}

/*
 * Fonction qui permet de recalculer le déplacement de la balle en
 * x et en y affin d'avoir toujours la bonne vitesse.
 * 
 * x_move : le déplacement de la balle en x
 * y_move : le déplacement de la balle en y
 */
void speedUpdate(double* x_move, double* y_move) {
	double hypo = sqrt((*x_move * *x_move) +(*y_move * *y_move));	// L'hypoténus du rectangle
	double coef = hypo / BAL_FAST;									// Le coefficient de réduction à appliquer
	*x_move /= coef;
	*y_move /= coef;
}
