#include "sort.h"

/**
 * swap - func
 * @a: val
 * @b: val
 */
void swap(int *a, int *b)
{
	if (a != b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

/**
 * partition - func
 * @array: val
 * @low: val
 * @high: val
 * @size: val
 * Return: low value
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}
	swap(&array[i], &array[high]);
    print_array(array, size);
	return (i);
}

/**
 * quick_sort_helper - func
 * @array: val
 * @low: val
 * @high: val
 * @size: val
 */
void quick_sort_helper(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		if (pivot_index > 0)
		{
			quick_sort_helper(array, low, pivot_index - 1, size);
		}
		quick_sort_helper(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - func
 * @array: val
 * @size: val
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(array, 0, size - 1, size);
}
