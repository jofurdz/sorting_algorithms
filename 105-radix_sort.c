#include "sort.h"
/**
 * getMax - gets the largest element from an array
 * @array: array
 * @n: int
 * Return: largest element from array
 */
int getMax(int array[], int n)
{
	int i;
	int max = array[0];

	for (i = 1; i < n; i++)
		if (array[i] > max)
		max = array[i];
	return (max);
}
/**
 * countingSort - sorts elements
 * @array: array to be sorted
 * @size: size of array
 * @buff: buffer
 * @lsd: least significant digit
 */
void countingSort(int *array, size_t size, int *buff, int lsd)
{
	int arrCount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t idx;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (idx = 0; idx < size; idx++)
	{
		arrCount[(array[idx] / lsd) % 10]++;
	}
	for (idx = 1; idx < 10; idx++)
	{
		arrCount[idx] += arrCount[idx - 1];
	}
	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		buff[arrCount[(array[idx] / lsd) % 10] - 1] = array[idx];
		arrCount[(array[idx] / lsd) % 10]--;
	}

	for (idx = 0; idx < size; ++idx)
		array[idx] = buff[idx];
}
/**
 * radix_sort - sorts an array of ints using radix sort algorithim
 * @array: array to be sorted
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int max, *temp, LSD;

	if (array == NULL || size < 2)
		return;
	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;
	max = getMax(array, size);
	for (LSD = 1; max / LSD > 0; LSD *= 10)
	{
		countingSort(array, size, temp, LSD);
		print_array(array, size);
	}
	free(temp);
}
