#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <locale.h>  // setlocale
#include <stdbool.h>
#include <time.h>

#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 803
#define COLOR_BIT 32
#define RECTX 11							// Nombre de rect en x
#define RECTY 7								// Nombre de rect en y
#define NB_CASE RECTX*RECTY					// Nombre totale de casse jouable dans le jeux
#define RECTW SCREEN_WIDTH / RECTX			// W des rects
#define RECTH (SCREEN_HEIGHT / 2) / RECTY	// H des rects

#define SLIDER_W 100
#define SLIDER_H 30
#define SLIDER_X (SCREEN_WIDTH - SLIDER_W) / 2
#define SLIDER_Y (SCREEN_HEIGHT - (SLIDER_H*2))

#define BAL_H 15
#define BAL_W 15
#define BAL_X (SCREEN_WIDTH - BAL_W) / 2
#define BAL_Y SCREEN_HEIGHT - (SLIDER_H*3) - 100

#define BAL_FAST 10

void cleanup(SDL_Window* fenetre, SDL_Renderer* ren, SDL_Texture* tex, FILE* log);
void getLogPath(char* logName[]);
void getFormatedTime(char* time_f[]);
void init();