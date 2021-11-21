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

void radix_sort(int *list, int n)
{
	int result[MAX], maxValue = 0;
	int exp = 1;
	for (int i = 0; i < n; i++)
	{
		if (list[i] > maxValue)
			maxValue = list[i];
	}
	while (maxValue / exp > 0)
	{ // 1의 자릿수 계산
		int bucket[10] = {0};
		for (int i = 0; i < n; i++)
			bucket[list[i] / exp % 10]++; // 자릿수 배열 처리
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1]; // 누적 계산 : 결과 배열을 만들기 위해서!
		for (int i = n - 1; i >= 0; i--)
		{ //같은 자릿수 끼리는 순서를 유지
			result[--bucket[list[i] / exp % 10]] = list[i];
		}
		for (int i = 0; i < n; i++)
			list[i] = result[i]; // 기본 배열 갱신
		exp *= 10;
	}
}