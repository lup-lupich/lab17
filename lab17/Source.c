#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"
#include "sort.h"

int lab17_task1(int* ptr_array, int size, int user_choise);
int lab17_task2(int* ptr_array, int size);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	int array[10000];
	int size;
	int user_choise;

	printf("ЗАДАНИЕ 1:\n\n");

	printf("Введите размер массива: ");
	scanf("%d", &size);
	full_array(array, size);
	put_array(array, size);
	
	printf("Выберите сортировку (BUBBLE - 1, COCKTAIL - 2, SELECTION - 3, INSERTION - 4): ");
	scanf("%d", &user_choise);
	printf("\n");

	lab17_task1(array, size, user_choise);

	return 0;
}


int lab17_task1(int* ptr_array, int size, int user_choise) {

	switch (user_choise) {

	case 1:
		printf("BUBBLE SORT:\n\n");
		bubble_sort(ptr_array, size);

		put_array(ptr_array, size);

		break;

	case 2:
		printf("COCKTAIL SORT:\n\n");
		cocktail_sort(ptr_array, size);

		put_array(ptr_array, size);

		break;

	case 3:
		printf("SELECTION SORT:\n\n");
		selection_sort(ptr_array, size);

		put_array(ptr_array, size);

		break;

	case 4:	
		printf("INSERTION SORT:\n\n");
		insertion_sort(ptr_array, size);

		put_array(ptr_array, size);

		break;
	}

	return 0;
}

