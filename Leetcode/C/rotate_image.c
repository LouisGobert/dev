#include "Header.h"
#include "array.h"


void rotateHelper(int matrix[4][4], int matrixSize, int xShift) {

	if (matrixSize == 1)
		return;

	int xspos, turn, turnPos, temp, newX, newY, oldX, oldY, oldTemp;

	/// -1 car si un carré de 4 de longueur, il suffit de changer
	///  les 3 premiers pour en réalité changer les 4.
	/// 
	///			####	'''#
	///			OOOO	=> #   
	///			BBBB	   #	
	///			%%%%	   #
	/// 
	for (turn = 0; turn < matrixSize - 1; turn++) {
		//xspos = turn;
		newX = turn + xShift;
		newY = 0 + xShift;
		temp = matrix[newY][newX];
		for (turnPos = 0; turnPos < 4; turnPos++) {
			//oldX = newX;
			//oldY = newY;
			oldTemp = temp;
			switch (turnPos)
			{
			case 0:
				newX = matrixSize - 1;
				newY =  turn;
				break;
			case 1:
				newY = matrixSize - 1;
				newX = matrixSize - 1 - turn;
				break;
			case 2 :
				newY = matrixSize - 1 - turn;
				newX = 0;
				break;
			default:
				newY = 0;
				newX = turn;
				break;
			}

			newY += xShift;
			newX += xShift;

			temp = matrix[newY][newX];
			//printf("Push de %d en {%d : %d} -> new temp = %d\n", oldTemp, newX, newY, temp);
			matrix[newY][newX] = oldTemp;
		}
		printArray2D(matrix, 4, 4);
	}
}

void rotate(int matrix[4][4], int matrixSize, int* matrixColSize) {

	int lShift = 0, rShift = matrixSize-1;
	while (lShift < rShift)
	{
		rotateHelper(matrix, matrixSize - (lShift *2), lShift);
		lShift++;
		rShift--;

	}

}

void updatePos(int *x, int *y) {

	int *temp = y;
	*y = *x;
	*x = temp;
}



//void main() {
//
//	int tab[4][4];
//	for (int i = 0; i < 16; i++)
//		tab[i / 4][i % 4] = i;
//
//	printArray2D(*tab, 4, 4);
//
//	int p = 4;
//	rotate(tab, 4, &p);
//	printf("\n\n\n");
//
//	printArray2D(*tab, 4, 4);
//
//}