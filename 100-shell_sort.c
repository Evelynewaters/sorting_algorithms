#include "sort.h"

/**
 * shell_sort - the shell sort algorithm
 * @array: the array to be sorted
 * @size: Array size
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, gap;

	if (array && size > 1)
	{
		for (gap = 1; gap * 3 + 1 < size; gap = gap * 3 + 1)
			;
		for (; gap; gap = (gap - 1) / 3)
		{
			for (i = gap; i < size; ++i)
			{
				tmp = array[i];
				for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
					array[j] = array[j - gap];
				array[j] = tmp;
			}
			print_array(array, size);
		}
	}
}
