#include <stdio.h>
#include <stddef.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array using selection
 *
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t minIndex;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;
	}
	print_array(array, size);
}
