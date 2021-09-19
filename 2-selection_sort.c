#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *
 * @array: array
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - swaps array
 *
 * @xp: array 1
 * @yp: array 2
 */

void swap(int *xp, int *yp)
{
	size_t temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}
