#include "sort.h"

/**
 * swapp - it swaps specified array elements before printing
 * @array: the array to swap elements
 * @size: Array size
 * @i: the first index to swap
 * @j: the second index to swap
 */
void swapp(int *array, size_t size, int i, int j)
{
	int tmp;

	tmp = array[j];
	if (array[i] != array[j])
	{
		array[j] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}

/**
 * partition - Partitions array based on pivot
 * @array: Array to sort
 * @size: Size of array
 * @lo: Start index
 * @hi: End index
 *
 * Return: Position of partition
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; ++j)
		if (array[j] < pivot)
		{
			++i;
			swapp(array, size, i, j);
		}
	++i;
	swapp(array, size, i, hi);
	return (i);
}

/**
 * quicksort - the recursion funtion
 * @array: the array to sway elements
 * @size: Array size
 * @lo: the start index
 * @hi: the end index
 */
void quicksort(int *array, size_t size, int lo, int hi)
{
	int p;

	if  (lo < hi)
	{
		p = partition(array, size, lo, hi);
		quicksort(array, size, lo, p - 1);
		quicksort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - A quick sort algorithm
 * @array: the array to swap elements
 * @size: Array size
 */
void quick_sort(int *array, size_t size)
{
	if (array)
		quicksort(array, size, 0, size - 1);
}
