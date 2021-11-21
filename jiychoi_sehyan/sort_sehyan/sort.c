#include "sort.h"

void selection_sort(int *list)
{
	int tmp;

	for (int i = 0; i < MAX; i++) {
		for (int j = i+1; j < MAX; j++) {
			if (list[j] < list[i]) {
				tmp = list[j];
				list[j] = list[i];
				list[i] = tmp;
			}
		}
	}
}

void quick_sort(int *list, int left, int right)
{
	int i = left + 1;
	int j = right;
	int pivot = left;
	int tmp;

	if (left >= right)
		return ;

	while (i <= j) {
		while (i <= right && list[pivot] >= list[i])
			i++;
		while (j > left && list[pivot] <= list[j])
			j--;
		if (i > j) {
			tmp = list[j];
			list[j] = list[pivot];
			list[pivot] = tmp;
		} else {
			tmp = list[i];
			list[i] = list[j];
			list[j] = tmp;
		}
	}
	quick_sort(list, left, j-1);
	quick_sort(list, j+1, right);
}

void shell_insert_sort(int *list, int start, int end, int interval)
{
	int item = 0;
	int idx = 0;

	for (int i = start + interval; i <= end; i = i+interval) {
		item = list[i];
		idx = i - interval;
		while ((idx >= start) && item < list[idx]) {
			list[idx + interval] = list[idx];
			idx = idx - interval;
		}
		list[idx + interval] = item;
	}
}

void shell_sort(int *list, int count)
{
	int interval = 0;

	interval = count / 2;
	while (interval >= 1) {
		for (int i = 0; i < interval; i++) {
			shell_insert_sort(list, i, count - 1, interval);
		}
		interval = interval / 2;
	}
}

void radix_sort(int *list)
{

}