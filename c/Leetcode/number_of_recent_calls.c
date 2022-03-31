#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int counter[3002];
	int pos;
	int nb_call;
	int pos_low_ping;
} RecentCounter;


RecentCounter* recentCounterCreate() {
	RecentCounter* rc = malloc(sizeof * rc);
	rc->counter[0] = 0;
	rc->pos = 0;
	rc->nb_call = 0;
	rc->pos_low_ping = 0;
	return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {

	obj->nb_call++;
	obj->counter[obj->pos] = t;

	obj->pos = (obj->pos + 1) % 3002;

	// Seulement si le pin min > t- 3000

	while (obj->counter[obj->pos_low_ping] < t - 3000) {

		obj->counter[obj->pos_low_ping] = 0;
		obj->pos_low_ping++;
		obj->pos_low_ping %= 3002;
		obj->nb_call--;
	}
	return obj->nb_call;


}

void recentCounterFree(RecentCounter* obj) {
	free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);

 * recentCounterFree(obj);
*/

