#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"
#include "sort.h"

int lab17_task1(int* ptr_array);
int lab17_task2(int* ptr_array);
double bubble_sort_time(int* ptr_array, int size);
double cocktail_sort_time(int* ptr_array, int size);
double selection_sort_time(int* ptr_array, int size);
double insertion_sort_time(int* ptr_array, int size);

int main(void) {

	setlocale(LC_CTYPE, "RUS");

	int array[10000];
	int choise_task;

	long ltime = time(NULL) / 2;
	int stime = (unsigned)ltime;
	srand(stime);

	printf("Выберите задание (1 или 2): ");
	scanf("%d", &choise_task);
	printf("\n");
	
	switch (choise_task) {
		case 1:
			printf("ЗАДАНИЕ 1:\n\n");

			lab17_task1(array);;

			break;

		case 2:
			printf("ЗАДАНИЕ 2:\n\n");

			lab17_task2(array);

			break;

		default:
			printf("Такого задания нет\n");
			break;
	}
	return 0;
}


int lab17_task1(int* ptr_array) {

	int user_choise;
	int size;

	printf("Введите размер массива: ");
	scanf("%d", &size);
	full_array(ptr_array, size);
	put_array(ptr_array, size);


	printf("Выберите сортировку (BUBBLE - 1, COCKTAIL - 2, SELECTION - 3, INSERTION - 4): ");
	scanf("%d", &user_choise);
	printf("\n");

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

int lab17_task2(int* ptr_array) {
	
	double time;
	double sum = 0;

	//BUBBLE SORT, RAND_ARRAY

	printf("BUBBLE SORT, массив заполен случайно\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array(ptr_array, 100);
		time = bubble_sort_time(ptr_array, 100);
		sum += time;
	}

	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {

		full_array(ptr_array, 1000);
		time = bubble_sort_time(ptr_array, 1000);
		sum += time;
	}

	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {

		full_array(ptr_array, 10000);
		time = bubble_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//BUBBLE SORT, RAND_ARRAY_SORT_75%

	printf("BUBBLE SORT, массив отсортирован на 75%%\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_sort_75(ptr_array, 100);
		time = bubble_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {

		full_array_sort_75(ptr_array, 1000);
		time = bubble_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {

		full_array_sort_75(ptr_array, 10000);
		time = bubble_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//BUBBLE SORT, ARRAY_ALMOST_SORT

	printf("BUBBLE SORT, массив почти отсортирован\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_almost_sort(ptr_array, 100);
		time = bubble_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {

		full_array_almost_sort(ptr_array, 1000);
		time = bubble_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {

		full_array_almost_sort(ptr_array, 10000);
		time = bubble_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//BUBBLE SORT, RAND_ARRAY_SORT_REVERSE%

	printf("BUBBLE SORT, массив отсортирован в обратном порядке\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_sort_reverse(ptr_array, 100);
		time = bubble_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {

		full_array_sort_reverse(ptr_array, 1000);
		time = bubble_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_reverse(ptr_array, 10000);
		time = bubble_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//COCKTAIL SORT, RAND_ARRAY

	printf("COCKTAIL SORT, массив заполен случайно\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array(ptr_array, 100);
		time = cocktail_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array(ptr_array, 1000);
		time = cocktail_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array(ptr_array, 10000);
		time = cocktail_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//COCKTAIL SORT, RAND_ARRAY_SORT_75%

	printf("COCKTAIL SORT, массив отсортирован на 75%%\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_sort_75(ptr_array, 100);
		time = cocktail_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_75(ptr_array, 1000);
		time = cocktail_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_75(ptr_array, 10000);
		time = cocktail_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//COCKTAIL SORT, ARRAY_ALMOST_SORT

	printf("COCKTAIL SORT, массив почти отсортирован\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array_almost_sort(ptr_array, 100);
		time = cocktail_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_almost_sort(ptr_array, 1000);
		time = cocktail_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_almost_sort(ptr_array, 10000);
		time = cocktail_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//COCKTAIL SORT, RAND_ARRAY_SORT_REVERSE%

	printf("COCKTAIL SORT, массив отсортирован в обратном порядке\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_reverse(ptr_array, 100);
		time = cocktail_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_reverse(ptr_array, 1000);
		time = cocktail_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_reverse(ptr_array, 10000);
		time = cocktail_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//SELECTION SORT, RAND_ARRAY

	printf("SELECTION SORT, массив заполен случайно\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array(ptr_array, 100);
		time = selection_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array(ptr_array, 1000);
		time = selection_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array(ptr_array, 10000);
		time = selection_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//SELECTION SORT, RAND_ARRAY_SORT_75%

	printf("SELECTION SORT, массив отсортирован на 75%%\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_75(ptr_array, 100);
		time = selection_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_75(ptr_array, 1000);
		time = selection_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_75(ptr_array, 10000);
		time = selection_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//SELECTION SORT, ARRAY_ALMOST_SORT

	printf("SELECTION SORT, массив почти отсортирован\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_almost_sort(ptr_array, 100);
		time = selection_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_almost_sort(ptr_array, 1000);
		time = selection_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_almost_sort(ptr_array, 10000);
		time = selection_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//SELECTION SORT, RAND_ARRAY_SORT_REVERSE%

	printf("SELECTION SORT, массив отсортирован в обратном порядке\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_reverse(ptr_array, 100);
		time = selection_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_reverse(ptr_array, 1000);
		time = selection_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_reverse(ptr_array, 10000);
		time = selection_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//INSERTION SORT, RAND_ARRAY

	printf("INSERTION SORT, массив заполен случайно\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array(ptr_array, 100);
		time = insertion_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array(ptr_array, 1000);
		time = insertion_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array(ptr_array, 10000);
		time = insertion_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//INSERTION SORT, RAND_ARRAY_SORT_75%

	printf("INSERTION SORT, массив отсортирован на 75%%\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_sort_75(ptr_array, 100);
		time = insertion_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_75(ptr_array, 1000);
		time = insertion_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_75(ptr_array, 10000);
		time = insertion_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//INSERTION SORT, ARRAY_ALMOST_SORT

	printf("INSERTION SORT, массив почти отсортирован\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {

		full_array_almost_sort(ptr_array, 100);
		time = insertion_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_almost_sort(ptr_array, 1000);
		time = insertion_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_almost_sort(ptr_array, 10000);
		time = insertion_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	//INSERTION SORT, RAND_ARRAY_SORT_REVERSE%

	printf("INSERTION SORT, массив отсортирован в обратном порядке\n\n");

	//100 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_reverse(ptr_array, 100);
		time = insertion_sort_time(ptr_array, 100);
		sum += time;
	}
	printf("100 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;


	//1000 el
	for (int i = 0; i < 50; i++) {
		full_array_sort_reverse(ptr_array, 1000);
		time = insertion_sort_time(ptr_array, 1000);
		sum += time;
	}
	printf("1000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 50);
	sum = 0;

	//10000 el
	for (int i = 0; i < 10; i++) {
		full_array_sort_reverse(ptr_array, 10000);
		time = insertion_sort_time(ptr_array, 10000);
		sum += time;
	}
	printf("10000 элементов:\n\n");
	printf("Среднее время сортировки: %.12f секунд\n\n", sum / 10);
	sum = 0;

	return 0;
}

double bubble_sort_time(int* ptr_array, int size) {

	clock_t t = clock();

	bubble_sort(ptr_array, size);

	double time = (clock() - t) * 1. / CLOCKS_PER_SEC;

	return time;
}

double cocktail_sort_time(int* ptr_array, int size) {

	clock_t t = clock();

	cocktail_sort(ptr_array, size);

	double time = (clock() - t) * 1. / CLOCKS_PER_SEC;

	return time;
}

double selection_sort_time(int* ptr_array, int size) {

	clock_t t = clock();

	selection_sort(ptr_array, size);

	double time = (clock() - t) * 1. / CLOCKS_PER_SEC;

	return time;
}

double insertion_sort_time(int* ptr_array, int size) {

	clock_t t = clock();

	insertion_sort(ptr_array, size);

	double time = (clock() - t) * 1. / CLOCKS_PER_SEC;

	return time;
}