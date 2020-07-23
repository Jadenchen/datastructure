#include <stdio.h>
#if 1
//! merge two subarray
//! first array a[left, m]
//! second array a[m+1, right]
void merge(int *arr, int left, int middle, int right)
{
	int i, j, k;
	int n1, n2;
	n1 = middle - left + 1;
	n2 = right - middle;
	int Left[n1];
	int Right[n2];
	for(i = 0; i < n1; i++)
		Left[i] = arr[left+i];
	for(j = 0; j < n2; j++)
		Right[j] = arr[middle + 1 + j];

	i = 0; //! for first array index
	j = 0; //! for second array index
	k = left; //for merged array index 

	while(i < n1 && j < n2)
	{
		if(Left[i] <= Right[j])
		{
			arr[k++] = Left[i++];
		//	i++;
		} else 
		{
			arr[k++] = Right[j++];
		//	j++;
		}
		//k++;
	}

	//! copy remain 
	while(i < n1)
	{
		arr[k++] = Left[i++];
	}

	//copy remain array
	while(j < n2)
		arr[k++] = Right[j++];

}

void mergeSort(int *a, int left, int right)
{
	if(left < right)
	{
		int middle = left + (right - left)/2;
		mergeSort(a, left, middle);
		mergeSort(a, middle + 1, right);
		merge(a, left, middle, right);
	}
}
#else
void merge(int *arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    }  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int *arr, int l, int r) 
{ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

#endif
int main(void)
{
	int i;
	int len = 10;
	int a[] = {69, 81,30,38, 9, 2,47, 61, 32, 80};
	mergeSort(a, 0, len -1);
	for(i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
