#include "Header.h"

uint32_t reverseBits(uint32_t n) {

	int i;
	uint32_t rightSet, leftSet;
	uint32_t l = (uint32_t)(1) << 31, r = 1;

	// Unset test
	//l &= ~(1 << 31);

	for (i = 0; i < 16; i++) {

		// memo of right bit
		rightSet = r & n;
		leftSet = l & n;

		// If left bit set
		if ((rightSet && !leftSet) || (!rightSet && leftSet)) {
			// n - la bit set
			if (rightSet) {
				n &= ~(r);
				n |= (l);
			}
			else {
				n &= ~(l);
				n |= r;
			}
			
		}

		r <<= 1;
		l >>= 1;
	}

	return n;
}


//void main() {
//
//	uint32_t n = 0b00000010100101000001111010011100;
//	uint32_t res = reverseBits(n);
//	printf("%d", res);
//}

//               0000 0010 1001 0100 0001 1110 1001 1100
//    964176192 (0011 1001 0111 1000 0010 1001 0100 0000) <- coorect
//    964174144 (0011 1001 0111 1000 0010 0001 0100 0000)