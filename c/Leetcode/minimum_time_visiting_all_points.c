#include "Header.h"


//int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
//
//	int i, x, y, xx, yy, time =0;
//	for (i = 0; i < pointsSize-1; i++) {
//		x = points[i][0];
//		y = points[i][1];
//
//		xx = points[i + 1][0];
//		yy = points[i + 1][1];
//
//		while (y != yy || x != xx)
//		{
//
//
//			if (x == xx) {
//				time += abs(y - yy);
//				y = yy;
//			}
//			else if (y == yy) {
//				time += abs(x - xx);
//				x = xx;
//			}
//			else {
//				x += (xx - x > 0) ? 1 : -1;
//				y += (yy - y > 0) ? 1 : -1;
//				time++;
//			}
//		}
//		
//	}
//
//	return time;
//}

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {

	int time = 0, i, x, y;
	for (i = 0; i < pointsSize-1; i++) {

		x = abs(points[i][0] - points[i + 1][0]);
		y = abs(points[i][1] - points[i + 1][1]);

		if (x > y)
			time += x;
		else
			time += y;
	}

	return time;
}

//void main() {
//	int tabb[3][2] = { {1, 1},{3, 4},{-1, 0} };
//	int** tab = malloc(sizeof(int*) * 3);
//	for (int i = 0; i < 3; i++) {
//		tab[i] = malloc(sizeof(int) * 2);
//		tab[i] = tabb[i];
//	}
//
//
//	int tabSize = 2;
//	int time = minTimeToVisitAllPoints(tab, 3, &tabSize);
//}