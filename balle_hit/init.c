#include "init.h"

void initLogPath(char* logName[]) {

	char time_f[24];

	time_t secondes;
	struct tm now;
	time(&secondes);
	now = *localtime(&secondes);
	sprintf(time_f, "[%d-%d-%d]-%02dh%02dm%02ds", (now.tm_year + 1900), now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);

	sprintf(logName, "log/%s.txt", time_f);

}


void initVideo() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(log, "\nErreur de chargement de SDL, erreur : %s", SDL_GetError());
		cleanup(NULL, NULL, NULL, log);
		return EXIT_FAILURE;
	}
	// On chache le curseur de la souris
	SDL_ShowCursor(false);
	SDL_SetRelativeMouseMode(true);


}

void initRect(bool game[], SDL_Rect* rect) {
	int pos = 0;
	for (int i = 0; i < NB_CASE; i++) {

		// On cr�e le rectangle uniquement si il vaut true dans la config du jeux
		if (game[i]) {
			rect[pos].h = RECTH;
			rect[pos].w = RECTW;
			rect[pos].x = (i * RECTW) % SCREEN_WIDTH;
			rect[pos].y = ((i / RECTX) * (RECTH - 1)); // -1 pour r�soudre beug daffichage pixel
			pos++;
		}
	}

	rect[pos].h = BAL_H;
	rect[pos].w = BAL_W;
	rect[pos].x = BAL_X;
	rect[pos].y = BAL_Y;

	pos++;

	rect[pos].h = SLIDER_H;
	rect[pos].w = SLIDER_W;
	rect[pos].x = SLIDER_X;
	rect[pos].y = SLIDER_Y;

}

int initGame(bool* game, bool* start_game, FILE* log) {
	FILE* gameFile = fopen("game/1.txt", "r");

	// Log
	fprintf(log, "\nLecture du jeux :\n-----------");

	int cara = 0, pos = 0, nbCasse = 0;
	bool valCara;

	do {
		valCara = false;
		cara = fgetc(gameFile);
		if (cara == 48 || cara == 49) {
			if (cara == 49) {
				valCara = true;
				nbCasse++;
			}
			else cara = 32;
			game[pos] = valCara;
			start_game[pos] = valCara;

			// Affichage du jeux obtenu dans les logs
			(pos % NB_CASE == 0) ? fprintf(log, "\n%c", cara) : fprintf(log, "%c", cara);

			pos++;
		}
	} while (cara != EOF); // temps que l'on est pas a la fin du fichier
	fclose(gameFile);
	fprintf(log, "\n----------\nFin de la lecture, sucess.");

	return nbCasse;
}
