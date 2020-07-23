#include <stdio.h>

void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void bubble_sort(int *a, int len)
{
	int i, j;
	for(i = len -1; i > 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}
}

int main(void)
{
	int i;
	int len = 10;
	int a[] = {69, 81,30,38, 9, 2,47, 61, 32, 79};
	bubble_sort(a, len);
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
