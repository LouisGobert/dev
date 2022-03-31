#include "main.h"

int main(int argc, char* argv[])
{
	//-------------------------------------------------------------------------//
	//							Constante et variable						   //
	//-------------------------------------------------------------------------//

	SDL_Event e;		// Pour l'obtention des touches		
	bool quit = false;	// Si quit = true, la fenetre se ferme et extinction du programme.

	bool animation = false; // Si true, la bal est en mouvement
	int nbCasseJouable;			// Nombre de casse dans le jeux
	double x_move = 0;		// D�placement de d�part de la balle en x
	double y_move = 4;		// D�placement de d�part de la balle en y

	//-------------------------------------------------------------------------//
	//									LOG									   //
	//-------------------------------------------------------------------------//
	setlocale(LC_ALL, "");
	char logName[42];					// Cr�ation du tableau contenant le log
	initLogPath(&logName);				// Obtention du nom du log
	FILE* log = fopen(logName, "w");	// Cr�ation et ouverture du log
	fprintf(log, "D�marage du programme..."); // Ecriture du d�marrage corect


	//-------------------------------------------------------------------------//
	//					INITIALISATION DE FEN, REN							   //
	//-------------------------------------------------------------------------//
	initVideo();
	SDL_Window* fenetre = SDL_CreateWindow("Balle Hit Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_GRABBED);
	// Cr�ation d'une nouvelle fen�tre
	if (fenetre == NULL) {
		fprintf(log, "\nErreur lors de la cr�ation de la fen�tre, erreur : %s", SDL_GetError());
		cleanup(NULL, NULL, NULL, log);
		return EXIT_FAILURE;
	}
	// Moteur de rendu
	SDL_Renderer* ren = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL) {
		fprintf(log, "\nErreur lors de la cr�ation du moteur de rendu, erreur : %s", SDL_GetError());
		cleanup(fenetre, NULL, NULL, log);
		return EXIT_FAILURE;
	}


	//-------------------------------------------------------------------------//
	//																		   //
	//									INIT								   //
	//																		   //
	//-------------------------------------------------------------------------//

	/* On lit la partie depuis le txt
	 *game = jeux que l'on va modifi�e		true si casse est jou�e
	 *start_game jeux de base qu'on ne modifiera jamais
	 */

	bool game[NB_CASE], start_game[NB_CASE];		

	int nb_rect = initGame(&game, &start_game, log) + 2;	// Lecture du jeux depuis le txt
	int nb_block = nb_rect - 2, index_bal = nb_rect -2, index_slider = nb_rect-1;
	/* Tableau contenant toutes les casse + balle + slider
	 *
	 * De 0 a nbCasse -> les donn�e des rect de collision
	 * Avant derniere casse -> balle
	 * Derniere casse -> slider
	 */
	SDL_Rect* rect = malloc(sizeof(SDL_Rect) * (nb_rect)); // + 2 car on inclus la bal et le slider
	initRect(game, rect);	// Cr�ation des rectangles du jeux ainsi que les donn�es slider et balle
	


	//-------------------------------------------------------------------------//
	//																		   //
	//									JEUX								   //
	//																		   //
	//-------------------------------------------------------------------------//			

	// on affiche tout une premiere fois
	render(ren, rect, &game, start_game);

	// On attend un clic soit sur echap soit sur espace pour commenc�
	while (!animation) {
		SDL_WaitEvent(&e);
		
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				animation = true;
				break;
			case SDLK_SPACE:
				animation = true;
				break;
			default:
				break;
			}
		}
	}
	
	while (!quit && nb_block) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					quit = true;
					break;
				default:
					break;
				}
			}
			else if (e.type == SDL_MOUSEMOTION) {
				rect[index_slider].x += e.motion.xrel;
				if (rect[index_slider].x < 0) rect[index_slider].x = 0;
				else if (rect[index_slider].x > SCREEN_WIDTH - SLIDER_W) rect[index_slider].x = SCREEN_WIDTH - SLIDER_W;
			}
		}

		/*  
			- D�placement de la balle
			- Obtention du nombre de block restant
		*/
		nb_block = moveBal(&x_move, &y_move, &game, rect, nb_rect, start_game, nb_block);
		
		// On affiche tout
		render(ren, rect, &game, start_game);
		SDL_Delay(10);
	}
	


	
	// Fonction qui ferme tout et qui quit()
	fprintf(log, "\n\nNombre de block restant : %d\n\nFin du programme sans erreur :)", nb_block);
	free(rect);
	cleanup(fenetre, ren, NULL, log);
	return EXIT_SUCCESS;
}


/* Fonction qui permet de nettoyer les
 * resource SDL lors de la fin du programme.
 *
 * SDL_Window	: La fenetre windows principale (celle que l'on d�place)
 * SDL_Renderer : Le rendu inter fenetre
 * SDL_Surface	: La surface sur la quelle on va dessiner, afficher des images...
 * SDL_Texture	: Les textures (images, lignes..) a affich�
 */
void cleanup(SDL_Window *fenetre, SDL_Renderer *ren, SDL_Texture *tex, FILE* log) {
	(fenetre != NULL) ? SDL_DestroyWindow(fenetre) : 0;
	(ren != NULL) ? SDL_DestroyRenderer(ren) : 0;
	(tex != NULL) ? SDL_DestroyTexture(tex) : 0;
	fclose(log);
	SDL_Quit();
}


