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
	size_t i;
	
	if (size < 2 || array == NULL)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		size_t min_index = i;
		size_t j;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
