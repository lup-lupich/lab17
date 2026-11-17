#ifndef ARRAY_H
#define ARRAY_H

int put_array(int* ptr_array, int size); //вывод массива
int full_array(int* ptr_array, int size); //заполнение массива случайными числами
int full_array_sort_75(int* ptr_array, int size); //заполнение массива отсортированного на 75%
int full_array_sort_reverse(int* ptr_array, int size); //перевернутый отсортированный массив
int full_array_almost_sort(int* ptr_array, int size); //почти отсортированный массив

#endif