#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30

void display_list(int *list);
void init_list(int *list);

void selection_sort(int *list);
void quick_sort(int *list, int left, int right);
void shell_sort(int *list, int count);
void radix_sort(int *list);
// shell
// radix

#endif

#ifndef _COMMON_DEF_
#define _COMMON_DEF_

#define TRUE	1
#define FALSE	0

#endif