#include "Header.h"


void explore(char** grid, int gridSize, int* gridColSize, int x, int y) {
	if (grid[y][x] == '1') {
		grid[y][x] = '2';
		if (x != 0) explore(grid, gridSize, gridColSize, x - 1, y);
		if (y != 0) explore(grid, gridSize, gridColSize, x, y-1);
		if (y+1 < gridSize) explore(grid, gridSize, gridColSize, x, y+1);
		if (x + 1 < gridColSize[y]) explore(grid, gridSize, gridColSize, x+1, y);
	}
}



int numIslands(char** grid, int gridSize, int* gridColSize) {
	int nbIsland = 0;

	int x, y;
	for (y = 0; y < gridSize; y++) {
		for (x = 0;x < gridColSize[y]; x++) {
			if (grid[y][x] == '1') {
				nbIsland++;
				explore(grid, gridSize, gridColSize, x, y);
			}
			
		}
	}

	return nbIsland;
}



//void main() {
//	char griddd[4][5]  = {	{'1', '1', '0', '0', '0'},
//							{'1', '1', '0', '0', '0'}
//						,	{'0', '0', '1', 'O', '0'},
//							{'0', '0', '0', '1', '1'} };
//	char** grid = malloc(sizeof(char*) * 4);
//
//	for (int i = 0; i < 4; i++) {
//		grid[i] = griddd[i];
//	}
//
//
//	int colSize[] = { 5, 5, 5, 5 };
//	int res = numIslands(grid, 4, colSize);
//
//
//}