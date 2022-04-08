#ifndef __INC_UNIT
#define __INC_UNIT

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <math.h>   // fabs
#include <stdio.h>  // printf, sprintf
#include <string.h> // memcmp, strrchr
#include <time.h>   // clock, CLOCKS_PER_SEC

#define __USE_STDBOOL 1 // Mettre à 0 si la bibliothèque <stdbool.h> n'est pas utilisée

#if __USE_STDBOOL
# define __BOOL _Bool
#else
# define __BOOL int
#endif

#define MESSAGE_BUFFER_SIZE 200

char messageBuffer[MESSAGE_BUFFER_SIZE];

struct UnitTest {
	clock_t startTime;
	int runs;
	int failures;
} unitTest;

int compareArrays(const void *t1, const void *t2, int length, size_t datasize);
int compareFloatArrays(const float *t1, const float *t2, int length, float delta);
int checkIntArrayBetween(const int *t, int length, int lower, int upper);
int checkFloatArrayBetween(const float *t, int length, float lower, float upper, float delta);

/// <summary>
/// Initialise un test unitaire.
/// Cette opération est nécessaire afin de permettre la collecte d'informations lors de l'exécution des assertions qui lui succèdent.
/// </summary>
/// <remarks>
/// Les informations collectées sont le nombre de tests effectués, le nombre de tests en échec et le temps d'exécution des tests.
/// </remarks>
/// <param name="functionName">Le nom de la fonction testée.</param>
void initUnitTest(const char *functionName);

/// <summary>
/// Affiche les informations collectées pour un test unitaire.
/// </summary>
/// <remarks>
/// Cette opération nécessite l'exécution préalable de la fonction 'initUnitTest'.
/// </remarks>
void displayUnitTestReport();

/// <summary>Signale l'échec d'un test.</summary>
/// <param name="message">Un message expliquant la raison de l'échec du test.</param>
#define fail(message) \
	unitTest.failures++; \
	printf("  FAILURE: %s\n", message); \
	printf("    at %s: %d\n", strrchr(__FILE__, '\\') + 1, __LINE__); \

/// <summary>
/// Vérifie qu'une condition est vraie.
/// Si la condition n'est pas vraie, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="condition">La condition à tester.</param>
#define assertTrue(condition) \
	unitTest.runs++; \
	if (!condition) { \
		fail("expected <true> but was <false>"); \
	}

/// <summary>
/// Vérifie qu'une condition est fausse.
/// Si la condition n'est pas fausse, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="condition">La condition à tester.</param>
#define assertFalse(condition) \
	unitTest.runs++; \
	if (condition) { \
		fail("expected <false> but was <true>"); \
	}

/// <summary>
/// Vérifie que deux caractères sont égaux.
/// Si les valeurs ne sont pas égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur reçue.</param>
#define assertCharEquals(expected, actual) \
	{ \
		char lexpected = expected; \
		char lactual = actual; \
		unitTest.runs++; \
		if (lexpected != lactual) { \
			sprintf(messageBuffer, "expected <%c> but was <%c>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que deux caractères ne sont pas égaux.
/// Si les valeurs sont égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur reçue.</param>
#define assertCharNotEquals(expected, actual) \
	{ \
		char lexpected = expected; \
		char lactual = actual; \
		unitTest.runs++; \
		if (lexpected == lactual) { \
			sprintf(messageBuffer, "expected <%c> but was <%c>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que deux valeurs entières sont égales.
/// Si les valeurs ne sont pas égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur reçue.</param>
#define assertIntEquals(expected, actual) \
	{ \
		int lexpected = expected; \
		int lactual = actual; \
		unitTest.runs++; \
		if (lexpected != lactual) { \
			sprintf(messageBuffer, "expected <%d> but was <%d>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que deux valeurs entières ne sont pas égales.
/// Si les valeurs sont égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur reçue.</param>
#define assertIntNotEquals(expected, actual) \
	{ \
		int lexpected = expected; \
		int lactual = actual; \
		unitTest.runs++; \
		if (lexpected == lactual) { \
			sprintf(messageBuffer, "expected <%d> but was <%d>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que deux valeurs réelles sont égales.
/// Si les valeurs ne sont pas égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur reçue.</param>
/// <param name="delta">L'écart maximum admis entre la valeur attendue et la valeur reçue.</param>
#define assertFloatEquals(expected, actual, delta) \
	{ \
		float lexpected = expected; \
		float lactual = actual; \
		float ldelta = delta; \
		unitTest.runs++; \
		if (fabs(lexpected - lactual) > fabs(ldelta)) { \
			sprintf(messageBuffer, "expected <%g> but was <%g>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que deux valeurs réelles ne sont pas égales.
/// Si les valeurs sont égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">La valeur attendue.</param>
/// <param name="actual">La valeur reçue.</param>
/// <param name="delta">L'écart minimum admis entre la valeur attendue et la valeur reçue.</param>
#define assertFloatNotEquals(expected, actual, delta) \
	{ \
		float lexpected = expected; \
		float lactual = actual; \
		float ldelta = delta; \
		unitTest.runs++; \
		if (fabs(lexpected - lactual) <= fabs(ldelta)) { \
			sprintf(messageBuffer, "expected <%g> but was <%g>", lexpected, lactual); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que les éléments de deux tableaux de caractères sont égaux.
/// Si les valeurs ne sont pas égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">Le tableau contenant les valeurs attendues.</param>
/// <param name="actual">Le tableau contenant les valeurs reçues.</param>
/// <param name="length">La longueur des tableaux.</param>
#define assertCharArrayEquals(expected, actual, length) \
	{ \
		int index = compareArrays(expected, actual, length, sizeof(char)); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "arrays first differed at element [%d], expected <%c> but was <%c>", index, expected[index], actual[index]); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que les éléments de deux tableaux d'entiers sont égaux.
/// Si les valeurs ne sont pas égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">Le tableau contenant les valeurs attendues.</param>
/// <param name="actual">Le tableau contenant les valeurs reçues.</param>
/// <param name="length">La longueur des tableaux.</param>
#define assertIntArrayEquals(expected, actual, length) \
	{ \
		int index = compareArrays(expected, actual, length, sizeof(int)); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "arrays first differed at element [%d], expected <%d> but was <%d>", index, expected[index], actual[index]); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que les éléments de deux tableaux de réels sont égaux.
/// Si les valeurs ne sont pas égales, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="expected">Le tableau contenant les valeurs attendues.</param>
/// <param name="actual">Le tableau contenant les valeurs reçues.</param>
/// <param name="length">La longueur des tableaux.</param>
/// <param name="delta">L'écart maximum admis entre la valeur attendue et la valeur reçue.</param>
#define assertFloatArrayEquals(expected, actual, length, delta) \
	{ \
		int index = compareFloatArrays(expected, actual, length, delta); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "arrays first differed at element [%d], expected <%g> but was <%g>", index, expected[index], actual[index]); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que les éléments d'un tableau d'entiers sont compris dans un intervalle.
/// Si une valeur n'est pas comprise dans l'intervalle, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="actual">Le tableau contenant les valeurs reçues.</param>
/// <param name="length">La longueur du tableau.</param>
/// <param name="lower">La borne inférieure inclusive de l'intervalle.</param>
/// <param name="upper">La borne supérieure inclusive de l'intervalle.</param>
#define assertIntArrayBetween(actual, length, lower, upper) \
	{ \
		int index = checkIntArrayBetween(actual, length, lower, upper); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "element <%d> at index [%d] not included in the range from <%d> to <%d>", actual[index], index, lower, upper); \
			fail(messageBuffer); \
		} \
	}

/// <summary>
/// Vérifie que les éléments d'un tableau de réels sont compris dans un intervalle.
/// Si une valeur n'est pas comprise dans l'intervalle, le cas de test échoue et provoque l'affichage d'un message descriptif.
/// </summary>
/// <param name="actual">Le tableau contenant les valeurs reçues.</param>
/// <param name="length">La longueur du tableau.</param>
/// <param name="lower">La borne inférieure inclusive de l'intervalle.</param>
/// <param name="upper">La borne supérieure inclusive de l'intervalle.</param>
/// <param name="delta">L'excédent maximum admis entre la valeur reçue et les bornes de l'intervalle.</param>
#define assertFloatArrayBetween(actual, length, lower, upper, delta) \
	{ \
		int index = checkFloatArrayBetween(actual, length, lower, upper, delta); \
		unitTest.runs++; \
		if (index >= 0) { \
			sprintf(messageBuffer, "element <%g> at index [%d] not included in the range from <%g> to <%g>", actual[index], index, lower, upper); \
			fail(messageBuffer); \
		} \
	}

#endif /* __INC_UNIT */