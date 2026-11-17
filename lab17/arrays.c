#define XMIN 0
#define XMAX 100
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

int put_array(int* ptr_array, int size) {

	for (int i = 0; i < size; i++) {

		printf("%d элемент: %d\n", i + 1, *(ptr_array + i));
	}

	return 0;
}

int full_array(int* ptr_array, int size) {

	for (int i = 0; i < size; i++) {
		*(ptr_array + i) =  XMIN + (XMAX - XMIN) * rand() / RAND_MAX;
	}

	return 0;
}