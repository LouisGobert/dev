#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

typedef struct {
	char nom;
	float x;
	float y;
}point;

typedef struct {
	char nom[3 + 1];
	point points[3];
}triangle;

void afficher_point(const point *p);
float distance_points(const point *p1, const point *p2);
void deplacer_point(point *p, float dHorizontal, float dVertical);
void afficher_triangle(const triangle *adrT);
float perimetre_triangle(const triangle *adrT);
float aire_triangle(const triangle *adrT);
void deplacer_triangle(triangle *adrT);

main() {
	// Sp�cifier l'environnement linguistique
	setlocale(LC_ALL, "");

	point p1 = { 'A' }, p2 = { 'B' }, p3 = { 'C' };
	triangle t;

	//Point 5
	printf("Coordonn�es du point %c : ", p1.nom);
	scanf("%f %f", &p1.x, &p1.y);
	printf("Coordonn�es du point %c : ", p2.nom);
	scanf("%f %f", &p2.x, &p2.y);
	printf("Coordonn�es du point %c : ", p3.nom);
	scanf("%f %f", &p2.x, &p2.y);

	//Point 7
	afficher_point(&p1);
	afficher_point(&p2);
	afficher_point(&p3);

	//Point 9
	printf("Longueur des 3 c�t�s du triangle : %.1f ; %.1f ; %.1f\n", distance_points(&p1, &p2), distance_points(&p2, &p3), distance_points(&p3, &p1));

	//Point 11
	deplacer_point(&p1, -1, 2);
	deplacer_point(&p2, -1, 2);
	deplacer_point(&p3, -1, 2);

	afficher_point(&p1);
	afficher_point(&p2);
	afficher_point(&p3);
	
	//Point 13
	t.nom[0] = p1.nom;
	t.nom[1] = p2.nom;
	t.nom[2] = p3.nom;
	t.nom[3] = '\0';

	t.points[0] = p1;
	t.points[1] = p2;
	t.points[2] = p3;

	//Point 15
	afficher_triangle(&t);

	//Point 17
	printf("P�rim�tre du triangle %s : %.1f\n", t.nom, perimetre_triangle(&t));

	//Point 19
	printf("Aire du triangle %s : %.1f\n", t.nom, aire_triangle(&t));

	//Point21
	deplacer_triangle(&t);
	afficher_triangle(&t);

	_getch();
}

void afficher_point(const point *p) {
	printf("Point %c (%.1f ; %.1f)\n", p->nom, p->x, p->y);
}

float distance_points(const point *p1, const point *p2) {
	return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

void deplacer_point(point *p, float dHorizontal, float dVertical) {
	p->x += dHorizontal;
	p->y += dVertical;
}

void afficher_triangle(const triangle *adrT) {
	printf("Triangle %s : (%.1f ; %.1f), (%.1f ; %.1f) et (%.1f ; %.1f)\n", adrT->nom, adrT->points[0].x, adrT->points[0].y, adrT->points[1].x, adrT->points[1].y, adrT->points[2].x, adrT->points[2].y);
}

float perimetre_triangle(const triangle *adrT) {
	return distance_points(&((*adrT).points[0]), &((*adrT).points[1])) +
			distance_points(&(adrT->points[1]), &(adrT->points[2])) +
			distance_points(&(adrT->points[2]), &(adrT->points[0]));
}

float aire_triangle(const triangle *adrT) {
	float a = distance_points(&((*adrT).points[0]), &((*adrT).points[1]));
	float b = distance_points(&(adrT->points[1]), &(adrT->points[2]));
	float c = distance_points(&(adrT->points[2]), &(adrT->points[0]));
	float s = (a + b + c) / 2.0f;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}

void deplacer_triangle(triangle *adrT) {
	deplacer_point(&(adrT->points[0]), -4, -3);
	deplacer_point(&(adrT->points[1]), -4, -3);
	deplacer_point(&(adrT->points[2]), -4, -3);
}
