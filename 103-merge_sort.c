#include "sort.h"

/**
 * merge - merges 2 arrays
 * @array: array to be merged
 * @low: start of array
 * @middle: middle of array
 * @high: end of array
 * @temp: temporary array
 */
void merge(int *array, int low, int middle, int high, int *temp)
{
	int i, j, k, l = 0, r = 0, n, left[4096], right[4096];

	printf("Merging...\n");
	i = low, j = middle + 1, k = l = 0;
	while (i <= middle && j <= high)
	{
		if (array[i] <= array[j])
			temp[k] = left[l] = array[i], k++, i++, l++;
		else
			temp[k] = right[r] = array[j], k++, j++, r++;
	}
	while (i <= middle)
		temp[k] = left[l] = array[i], k++, i++, l++;
	while (j <= high)
		temp[k] = right[r] = array[j], k++, j++, r++;
	printf("[left]: ");
	for (n = 0; n < l; n++)
		(n == 0) ? printf("%d", left[n]) : printf(", %d", left[n]);
	printf("\n[right]: ");
	for (n = 0; n < r; n++)
		(n == 0) ? printf("%d", right[n]) : printf(", %d", right[n]);
	printf("\n[Done]: ");
	for (i = low; i <= high; i++)
	{
		array[i] = temp[i - low], printf("%d", array[i]);
		if (i != high)
			printf(", ");
		else
			printf("\n");
	}
}
/**
 * mergesort - uses merge sort algorithm
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @temp: temporary array
 */
void mergesort(int *array, int low, int high, int *temp)
{
    int m;

    if (low < high)
    {
        m = ((high + low -1) / 2);
        mergesort(array, low, m, temp);
        mergesort(array, m + 1, high, temp);
        merge(array, low, m, high, temp);
    }
}

/**
 * merge_sort - performs top-down merge sort
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void merge_sort(int *array, size_t size)
{
    int *widdly;

    if (array == NULL || size < 2)
        return;
    widdly = malloc(sizeof(int) * (size + 1));
    if (widdly == NULL)
        return;
    mergesort(array, 0, size - 1, widdly);
    free(widdly);
}
