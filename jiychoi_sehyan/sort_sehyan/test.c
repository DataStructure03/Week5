#include "sort.h"

void display_list(int *list)
{
	for (int i = 0; i < MAX; i++)
		printf("%d | ", list[i]);
	printf("\n");
}

void init_list(int *list)
{
	int i, j, k;

	srand((int)time(NULL));
	i = 0;
	while (i < MAX) {
		int randnum = rand() % MAX + 1;
		list[i] = randnum;
		for (j = 0, k = 0; j < i; j++) {
			if (list[i] == list[j]) {
				k = 1;
				break;
			}
		}
			if (k == 0)
				i++;
	}
}

int main()
{
	int list[MAX];

	init_list(list);

	display_list(list);

	printf("========SORTING==========\n");

	// selection_sort(list);
	// quick_sort(list, 0, MAX - 1);
	shell_sort(list, MAX);

	display_list(list);
	return (0);
}