#include "sort.h"

/**
 * swapp - it swaps specified array elements
 * @array: the array to swap elements
 * @size: Array size
 * @i: First index to be swaped
 * @j: Second index to be swaped
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
 * selection_sort - the selection sort algorithm
 * @array: the array to be sorted
 * @size: Array size
 */
void selection_sort(int *array, size_t size)
{
	size_t si, i;
	int min, min_pos, min_update;

	min_update = 0;
	if (array)
	{
		min = array[0];
		for (si = 0; si < size; ++si, min = array[si], min_update = 0)
		{
			for (i = si; i < size; ++i)
				if (min > array[i])
				{
					min = array[i];
					min_pos = i;
					min_update = 1;
				}
			if (min_update)
				swapp(array, size, si, min_pos);
		}
	}
}
