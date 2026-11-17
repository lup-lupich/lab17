#define XMIN 0
#define XMAX 100
#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"
#include "sort.h"

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

int full_array_sort_75(int* ptr_array, int size) {

	full_array(ptr_array, size);

	insertion_sort(ptr_array, size);

	int replace_el = size * 0.25;

	for (int i = 0; i < replace_el / 2; i++) {

		int a = rand() % size;
		int b = rand() % size;

		int temp = *(ptr_array + a);
		*(ptr_array + a) = *(ptr_array + b);
		*(ptr_array + b) = temp;
	}

	return 0;
}

int full_array_sort_reverse(int* ptr_array, int size) {

	full_array(ptr_array, size);

	insertion_sort(ptr_array, size);

	for (int i = 0; i < size / 2; i++) {

		int temp = *(ptr_array + i);
		*(ptr_array + i) = *(ptr_array + size - 1 - i);
		*(ptr_array + size - 1 - i) = temp;
	}

	return 0;
}

int full_array_almost_sort(int* ptr_array, int size) {

	full_array(ptr_array, size);

	insertion_sort(ptr_array, size);

	for (int i = 0; i < size - 1; i++) {

		int k = i + 1 + rand() % 5;

		if (k < size) {

			int temp = *(ptr_array + i);
			*(ptr_array + i) = *(ptr_array + k);
			*(ptr_array + k) = temp;
		}
	}
	
	return 0;
}