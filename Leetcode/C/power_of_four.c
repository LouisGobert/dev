#include "Header.h"



bool isPowerOfFour(int num) {
	if (num == 1)
		return true;
	else if (num < 1)
		return false;

	int power = 1;
	while (pow(4, power++) < num);
	
	if (pow(4, --power) == num)
		return true;
	return false;

	

}


//
//void main() {
//	bool t =  isPowerOfFour(16777216);
//
//}

