#include <stdio.h>
#include <limits.h>
#include "sort.h"

void bubble_sort(int* ptrarr, int size) {

	for (int i = 0; i < size; i++) {

		for (int k = 0; k < size - 1; k++) {

			if (*(ptrarr + k) >= *(ptrarr + k + 1)) {

				int temp = *(ptrarr + k);
				*(ptrarr + k) = *(ptrarr + k + 1);
				*(ptrarr + k + 1) = temp;
			}
		}
	}

}

void cocktail_sort(int* ptrarr, int size) {
	int left = 0, right = size - 1;

	while (left < right) {
		
		for (int l = left; l < right; l++) {
			
			if (*(ptrarr + l) >= *(ptrarr + l + 1)) {

				int temp = *(ptrarr + l);
				*(ptrarr + l) = *(ptrarr + l + 1);
				*(ptrarr + l + 1) = temp;
			}
		}

		right--;

		for (int r = right; r > left; r--) {

			if (*(ptrarr + r) <= *(ptrarr + r - 1)) {
				int temp = *(ptrarr + r);
				*(ptrarr + r) = *(ptrarr + r - 1);
				*(ptrarr + r - 1) = temp;
			}
		}

		left++;
	}
}

void selection_sort(int* ptrarr, int size) {

	for (int i = 0; i < size - 1; i++) {

		int min = *(ptrarr + i);

		for (int k = i + 1; k < size; k++) {

			if (*(ptrarr + k) <= *(ptrarr + i)) {

				min = *(ptrarr + k);
				*(ptrarr + k) = *(ptrarr + i);
				*(ptrarr + i) = min;
			}
		}
	}
}

void insertion_sort(int* ptrarr, int size) {

	for (int i = 1; i < size; i++) {

		int insert_element = *(ptrarr + i);
		int k = i - 1;

		while (k >= 0 && *(ptrarr + k) > insert_element) {
			*(ptrarr + k + 1) = *(ptrarr + k);
			k--;
		}

		*(ptrarr + k + 1) = insert_element;
	}
}