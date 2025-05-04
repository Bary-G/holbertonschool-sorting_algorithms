#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: given array
 * @size: size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	int temp;

	if (array == NULL || size == 0)
	{
		return;
	}

	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			print_array(array, size);
		}
	}
}
