#include <stdio.h>

void swap(int *pa, int *pb)
{
	if (pa != pb)
	{
		*pa ^= *pb;
		*pb ^= *pa;
		*pa ^= *pb;
	}
#if 0
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
#endif
}

int partition(int *a, int front, int end)
{
	//! choose the end index as pivot
	int pivot = a[end];
	//! record small array index
	int i = front - 1;
	//! record larget array index 
	int j;
	//! smaller pivot bigger
	for(j = front; j < end; j++)
	{
		if(a[j] < pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	}
	i++;
	swap(&a[i], &a[end]);
	return i;
}
//! front small array value index  
//! end bigger array value index
void quickSort(int *a, int front, int end)
{
	if(front < end)
	{
		int pivot = partition(a, front, end);
		quickSort(a, front, pivot - 1);
		quickSort(a, pivot + 1, end);
	}
}

int main(void)
{
	int i;
	int len = 10;
	int a[] = {69, 81,30,38, 9, 2,47, 61, 32, 80};
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\nquick sort \n");
	quickSort(a, 0, len -1);
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
