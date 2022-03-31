//#include "Header.h"
//#include "HashMap.h"
///*
//Design a HashMap without using any built-in hash table libraries.
//
//To be specific, your design should include these functions:
//
//put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
//get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
//remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
//*/
//
///** Initialize your data structure here. */
//
//HashMap* hashMapCreate() {
//	HashMap* root = malloc(sizeof(*root));
//
//	// 1000 est donc le nombre de bucket
//	root->hash = HASH_VALUE;
//
//	// Initialisation des buckets à NULL
//	root->bucket = malloc(sizeof(Bucket) * root->hash);
//	for (int i = 0; i < root->hash; i++) {
//		root->bucket[i] = NULL;
//	}
//
//	return root;
//}
//
///** value will always be non-negative. */
//void hashMapPut(HashMap* obj, int key) {
//
//	int hashKey = key % obj->hash;
//
//	// Si le bucket trouvé en fessant le haschage est vide
//	// Soit il est trouvé, on cherche alors pour voir si la clé y est déjà présente,
//	// Si c'est le cas, on met à jour la value.
//	// Si ce n'est pas le cas, on crée un nouveau seau qu'on place à la fin
//	if (!obj->bucket[hashKey]) {
//
//		
//		obj->bucket[hashKey] = malloc(sizeof(Bucket));
//		obj->bucket[hashKey]->key = key;
//		obj->bucket[hashKey]->value = 1;
//		obj->bucket[hashKey]->next = NULL;
//		
//	}
//	else {
//		// Parcour des bucket en recherche de clé
//		Bucket* temp = obj->bucket[hashKey];
//
//		while (temp && temp->next) {
//
//			// Si la clé est trouvée, maj de la valeur
//			if (temp->key == key) {
//				temp->value += 1;
//				return;
//			}
//			temp = temp->next;
//		}
//
//		/// Dans le cas ou le key et en derniere position.
//		if (temp->key == key) {
//			temp->value += 1;
//			return;
//		}
//
//		// On crée un nouveau bucket
//		temp->next = malloc(sizeof(Bucket));
//		temp->next->key = key;
//		temp->next->value = 1;
//		temp->next->next = NULL;
//
//	}
//}
//
///** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
//int hashMapGet(HashMap* obj, int key) {
//	int hashKey = key % obj->hash;
//
//	// On regarde si le bucket n'est pas vide
//	// Si non, on le parcour jusqu'a trouvé la clé
//	Bucket* temp = obj->bucket[hashKey];
//	if (temp) {
//		while (temp)
//		{
//			if (temp->key == key) return temp->value;
//			temp = temp->next;
//		}
//	}
//
//	// La clé n'a pas été trouvée
//	return -1;
//}
//
///** Removes the mapping of the specified value key if this map contains a mapping for the key */
//void hashMapRemove(HashMap* obj, int key) {
//
//	int hashKey = key % obj->hash, pos = 0, i = 0;
//
//	Bucket* t = obj->bucket[hashKey], *temp;
//	while (t && t->key != key) {
//		t = t->next;
//		pos++;
//	}
//
//	if (t && t->key == key) {
//
//		// Si la pos == 0, l'index de la clé à supprimé est le root.
//		//		-> On regarde donc si il y a quelque chose après, sinon = NULL
//		if (pos == 0) {
//			if (t->next)	obj->bucket[hashKey] = t->next;
//			else			obj->bucket[hashKey] = NULL;
//		}
//		else {
//			pos--;
//			temp = t;
//			t = obj->bucket[hashKey];
//			while (i++ != pos)
//				t = t->next;
//
//			if (t->next->next) t->next = t->next->next;
//			else t->next = NULL;
//
//			free(temp);
//		}
//		
//	}
//
//}
//
//void hashMapFree(HashMap* obj) {
//
//	// On vérifie que le bucket n'est pas vide
//	Bucket* temp, *buck;
//	for (int i = 0; i < obj->hash; i++) {
//		if (obj->bucket[i]) {
//			buck = obj->bucket[i]->next;
//			while (buck) {
//				temp = buck->next;
//				free(buck);
//				buck = temp;
//			}
//		}
//		free(obj->bucket[i]);
//	}
//	free(obj);
//}
//
///**
// * Your HashMap struct will be instantiated and called as such:
// * HashMap* obj = myHashMapCreate();
// * myHashMapPut(obj, key, value);
//
// * int param_2 = myHashMapGet(obj, key);
//
// * myHashMapRemove(obj, key);
//
// * myHashMapFree(obj);
//*/
//
////void main() {
////	HashMap* map = hashMapCreate();
////	
////	hashMapPut(map, 1, 1);
////	hashMapPut(map, 2, 2);
////
////	int p1 = hashMapGet(map, 1);
////	int p2 = hashMapGet(map, 3);
////
////	hashMapPut(map, 2, 1);
////	int p3 = hashMapGet(map, 2);
////
////	hashMapRemove(map, 2);
////
////	int p4 = hashMapGet(map, 2);
////
////
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// // VRAI VERSION
//
/////** Initialize your data structure here. */
////
////HashMap* hashMapCreate() {
////	HashMap* root = malloc(sizeof(*root));
////
////	// 1000 est donc le nombre de bucket
////	root->hash = HASH_VALUE;
////
////	// Initialisation des buckets à NULL
////	root->bucket = malloc(sizeof(Bucket) * root->hash);
////	for (int i = 0; i < root->hash; i++) {
////		root->bucket[i] = NULL;
////	}
////
////	return root;
////}
////
/////** value will always be non-negative. */
////void hashMapPut(HashMap* obj, int key, int value) {
////
////	int hashKey = key % obj->hash;
////
////	// Si le bucket trouvé en fessant le haschage est vide
////	// Soit il est trouvé, on cherche alors pour voir si la clé y est déjà présente,
////	// Si c'est le cas, on met à jour la value.
////	// Si ce n'est pas le cas, on crée un nouveau seau qu'on place à la fin
////	if (!obj->bucket[hashKey]) {
////
////
////		obj->bucket[hashKey] = malloc(sizeof(Bucket));
////		obj->bucket[hashKey]->key = key;
////		obj->bucket[hashKey]->value = value;
////		obj->bucket[hashKey]->next = NULL;
////
////	}
////	else {
////		// Parcour des bucket en recherche de clé
////		Bucket* temp = obj->bucket[hashKey];
////
////		while (temp->next) {
////
////			// Si la clé est trouvée, maj de la valeur
////			if (temp->key == key) {
////				temp->value = value;
////				return;
////			}
////			temp = temp->next;
////		}
////
////		/// Dans le cas ou le key et en derniere position.
////		if (temp->key == key) {
////			temp->value = value;
////			return;
////		}
////
////		// On crée un nouveau bucket
////		temp->next = malloc(sizeof(Bucket));
////		temp->next->key = key;
////		temp->next->value = value;
////		temp->next->next = NULL;
////
////	}
////}
////
/////** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
////int hashMapGet(HashMap* obj, int key) {
////	int hashKey = key % obj->hash;
////
////	// On regarde si le bucket n'est pas vide
////	// Si non, on le parcour jusqu'a trouvé la clé
////	Bucket* temp = obj->bucket[hashKey];
////	if (temp) {
////		while (temp)
////		{
////			if (temp->key == key) return temp->value;
////			temp = temp->next;
////		}
////	}
////
////	// La clé n'a pas été trouvée
////	return -1;
////}
////
/////** Removes the mapping of the specified value key if this map contains a mapping for the key */
////void hashMapRemove(HashMap* obj, int key) {
////
////	int hashKey = key % obj->hash, pos = 0, i = 0;
////
////	Bucket* t = obj->bucket[hashKey], * temp;
////	while (t && t->key != key) {
////		t = t->next;
////		pos++;
////	}
////
////	if (t && t->key == key) {
////
////		// Si la pos == 0, l'index de la clé à supprimé est le root.
////		//		-> On regarde donc si il y a quelque chose après, sinon = NULL
////		if (pos == 0) {
////			if (t->next)	obj->bucket[hashKey] = t->next;
////			else			obj->bucket[hashKey] = NULL;
////		}
////		else {
////			pos--;
////			temp = t;
////			t = obj->bucket[hashKey];
////			while (i++ != pos)
////				t = t->next;
////
////			if (t->next->next) t->next = t->next->next;
////			else t->next = NULL;
////
////			free(temp);
////		}
////
////	}
////
////}
////
////void hashMapFree(HashMap* obj) {
////
////	// On vérifie que le bucket n'est pas vide
////	Bucket* temp, * buck;
////	for (int i = 0; i < obj->hash; i++) {
////		if (obj->bucket[i]) {
////			buck = obj->bucket[i]->next;
////			while (buck) {
////				temp = buck->next;
////				free(buck);
////				buck = temp;
////			}
////		}
////		free(obj->bucket[i]);
////	}
////	free(obj);
////}
////
/////**
//// * Your HashMap struct will be instantiated and called as such:
//// * HashMap* obj = myHashMapCreate();
//// * myHashMapPut(obj, key, value);
////
//// * int param_2 = myHashMapGet(obj, key);
////
//// * myHashMapRemove(obj, key);
////
//// * myHashMapFree(obj);
////*/
////
//////void main() {
//////	HashMap* map = hashMapCreate();
//////	
//////	hashMapPut(map, 1, 1);
//////	hashMapPut(map, 2, 2);
//////
//////	int p1 = hashMapGet(map, 1);
//////	int p2 = hashMapGet(map, 3);
//////
//////	hashMapPut(map, 2, 1);
//////	int p3 = hashMapGet(map, 2);
//////
//////	hashMapRemove(map, 2);
//////
//////	int p4 = hashMapGet(map, 2);
//////
//////
//////}