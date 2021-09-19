#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 *
 * @array: array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, j, blah;

	for (x = 0; x < size; x++)
	{
		for (j = 0; j < size - x - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				blah = array[j];
				array[j] = array[j + 1];
				array[j + 1] = blah;
				print_array(array, size);
			}
		}
	}
}
