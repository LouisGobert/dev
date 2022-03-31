#include "Header.h"

// The API isBadVersion is defined for you.
bool isBadVersion(int version) {
	if (version > 3)
		return true;
	return false;
}

int firstBadVersion(int n) {
	if (n == 1)
		return isBadVersion(n);

	long start = 0, end = n - 1, m;
	while (start <= end)
	{
		m = (start + end) / 2;
		if (isBadVersion(m)) {
			end = m - 1;
		}
		else {
			start = m + 1;
		}
	}

	return (start+ end) /2;

}

//void main() {
//	int res = firstBadVersion(2126753390);
//}