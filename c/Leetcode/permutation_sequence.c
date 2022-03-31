#include "Header.h"
void mergee(int arr[], int l, int m, int r);

void merge_sortt(int arr[], int l, int r)
{
	if (l < r)
	{

		int m = l + (r - l) / 2;

		merge_sortt(arr, l, m);
		merge_sortt(arr, m + 1, r);

		mergee(arr, l, m, r);
		//printf("\Merge result : ");
		//print_array(arr, r+1);

	}
}

void mergee(int arr[], int l, int m, int r)
{
	// l    -> start tab 1
	// m    -> end tab 1 => start tab 2 + 1
	// r    -> end tab 2
	// pos  -> index de position dans le tableau posTab
	int taille = r - l + 1, temp_m = m + 1, temp_r = r + 1, pos = 0, temp_l = l;
	int* posTab = malloc(sizeof(int) * (taille));

	// On incrémente m pour l'utiliser comme index de pourcour du tab 2
	m++;

	while (l != temp_m && m != temp_r)
	{
		if (arr[l] > arr[m]) {
			posTab[pos] = arr[m];
			m++;
		}
		else {
			posTab[pos] = arr[l];
			l++;
		}
		pos++;
	}


	while (l != temp_m)
	{
		posTab[pos] = arr[l];
		l++;
		pos++;
	}
	while (m != temp_r)
	{
		posTab[pos] = arr[m];
		m++;
		pos++;
	}

	// Change le tab en fonction de posTab
	for (pos = 0; pos < taille; pos++)
		arr[temp_l + pos] = posTab[pos];


	// On désalloc le tableau
	free(posTab);

}


void swapp(int* nums, int id1, int id2) {
	int temp = nums[id1];
	nums[id1] = nums[id2];
	nums[id2] = temp;
}

void heapPermutes(int* nums, int* permutes, int* indexPermute, int size, int n) {
	if (size == 1) {
		permutes[*indexPermute] = 0;
		for (int i = n-1, x = 0; i >=0; i--,x++)
			permutes[*indexPermute] += nums[i] * (pow(10, x));
		printf("%d\n", permutes[*indexPermute]);

		(*indexPermute)++;
		return;
	}
	for (int i = 0; i < size; i++) {
		heapPermutes(nums, permutes, indexPermute, size - 1, n);

		if (size % 2 == 0) {
			swapp(nums, 0, size - 1);
		}
		else {
			swapp(nums, i, size - 1);
		}
	}
}


char* getPermutationnn(int n, int k) {
	/// Get permutes
	int i, permute, index;
	//int* nums = malloc(sizeof(int) * n);
	for (i = 1, permute = 1, index = 0; i <= n; i++, index++) {
		//nums[index] = i;
		permute *= i;
	}
	int indexPermute = 0;
	int* res = (int*)malloc(sizeof(int) * permute);

	int nums[] = { 1, 3, 5, 7 , 9};

	heapPermutes(nums, res, &indexPermute, n, n);


	// Sort
	merge_sortt(res, 0, permute -1);
	printf("\n\n");
	for (i = 0; i < permute; i++)
		printf("n = %d : %d\n", i+1, res[i]);


	// return
	char* s = malloc(sizeof(char)*n+1);
	for (i = n-1; i >=0; i--) {
		s[i] = (res[k - 1] %10) + '0';
		res[k - 1] /= 10;
	}
	s[n] = '\0';
	

	//free(res);
	return s;
}

int* getFirsTab(int n, int *n_permutation) {
	int* tab = malloc(sizeof(int) * n);
	*n_permutation = 1;
	for (int i = 1; i < n + 1; i++) {
		tab[i - 1] = i;
		(*n_permutation) *= i; // <- nombre de permuttation possible
	}

	return tab;
}

char* getPermutation(int n, int k) {

	int i, n_permutation = 1;
	int* tab = getFirsTab(n, &n_permutation);
	int changeEveryN;
	int N = n; /// <- no modify
	double tempNextIndex;
	int nextIndex;
	

	for (i = 0; i < N-1; i++) {
		changeEveryN = n_permutation / n;

		// Calcul de la prochaine casse
		tempNextIndex = ceil((double)k / changeEveryN);
		nextIndex = (int)tempNextIndex - 1;

		// Changement de casse avec casse actuelle vers casse souhaitée
		swapp(tab, i, nextIndex + i);

		// Triage du tableau
		merge_sortt(tab, i + 1, N - 1);

		k -= nextIndex * changeEveryN;

		printArray(tab, N);

		// Update des valeur

		n_permutation /= (N - i);
		n--;
	}

	char* s = malloc(sizeof(char) * N + 1);
	for (i = 0; i < N; i++) {
		s[i] = tab[i] + '0';
	}
	s[N] = '\0';
	
	free(tab);
	return s;
}



//void main() {
//
//	getPermutationnn(8, 28);
//	char* s = getPermutation(8,	28);
//	printf("%s", s);
//
//	
//}