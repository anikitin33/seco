#include <stdio.h>
#include <stdlib.h>

int main(void) {
   int n=0, max=10, z,i;
   int *zahlen=NULL;
   char * z_raw;

   /* Wir reservieren Speicher für 10 int-Werte mit calloc. */
   zahlen = calloc(max, sizeof(int));
   
   if(NULL == zahlen) {
      printf("Kein virtueller RAM mehr vorhanden");
      return EXIT_FAILURE;
   }
   
   printf("Zahlen eingeben --- Beenden mit 0\n");
   
   while(1) {
      printf("Zahl (%d) eingeben : ", n+1);
      scanf("%d", &z);
      if(z==0)
         break;
      /* Reservierung von Speicher während der Laufzeit
       * des Programms mit realloc */
       if(n >= max) {
          max += max;
          zahlen = realloc(zahlen,max*sizeof(int));
          if(NULL == zahlen) {
             printf("Kein virtueller RAM mehr vorhanden ... !");
             return EXIT_FAILURE;
          }
          printf("Speicherplatz reserviert "
                 " (%lu Bytes)\n", sizeof(int) * max);
       }
       zahlen[n++] = z;
   }
   
	int arr_size = n;

	printf("Given array is \n"); 
	printArray(zahlen, arr_size); 

	mergeSort(zahlen, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(zahlen, arr_size); 
	return 0; 
   
   
   free(zahlen);
   return EXIT_SUCCESS;
}

void merge(int arr[], int l, int m, int r) 
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
void mergeSort(int arr[], int l, int r) 
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

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("%d ", A[i]); 
	printf("\n"); 
} 

