#define _CRT_SECURE_NO_WARNINGS
#define N 4

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Function declarations */

void Ex1();
void Ex2();
void Ex31();
void Ex32();
void Ex4();

/* Declarations of other sub-functions */

int* input_array(int);
int areReversed(int*, int*, int);
int findCommonDigit(unsigned long long, unsigned long long);
int moveDuplicatesV1(int*, int);
int moveDuplicatesV2(int*, int);
int validateArray(int*, int);
int binSearch(int key, int* a, int n);
void quick_sort(int* x, int first, int last);
void array_print(int* a, int n);
void swap(int* v, int* u);
int split(int* a, int left, int right);
void quick_sort(int* x, int first, int last);


/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : \n", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: do {
				select = 0;
				printf("Ex31--->1\n");
				printf("Ex32--->2\n");
				printf("please select 1-2 : \n");
				scanf("%d", &select);
			} while ((select < 1) || (select > 2));
			switch (select)
			{
			case 1: Ex31(); break;
			case 2: Ex32(); break;
			};
			break;
			case 4: Ex4(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

void Ex1() {
	int n = 0;
	int* A, * B;
	printf("please enter the size of arrays: \n");
	scanf("%d", &n);
	printf("please enter elements of the first array: \n");
	A = input_array(n);
	printf("please enter elements of the second array: \n");
	B = input_array(n);
	areReversed(A, B, n) ? printf("Arrays are the opposite to one another.\n") : printf("Arrays are not the opposite to one another.\n");
	free(A); free(B);
}

void Ex2() {
	unsigned long long n1, n2;
	int answer = -2;
	printf("please enter two integers (64 bits) sorted in ascending order to find a common digit\n: ");
	scanf("%llu%llu", &n1, &n2);
	answer = findCommonDigit(n1, n2);
	switch (answer)
	{
	case -2: printf("Error in function.\n"); break;
	case -1: printf("%llu and %llu has no common digit.\n", n1, n2); break;
	default: printf("%llu and %llu common digit from right is: %d\n", n1, n2, answer); break;
	}
}

void Ex31() {
	int n = 0, i, answer = 0;
	int* A;
	printf("please enter the size of array: \n");
	scanf("%d", &n);
	printf("please enter elements of the array ranging from -%d to %d: \n", n, n);
	A = input_array(n);
	printf("Array before moving duplications: \n");
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nArray after moving duplications: \n");
	answer = moveDuplicatesV1(A, n);
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nThe number of different elements in array: %d.\n", answer);
	free(A);
}

void Ex32() {
	int n = 0, i, answer = 0;
	int* A;
	printf("please enter the size of array: \n");
	scanf("%d", &n);
	printf("please enter elements of the array: \n");
	A = input_array(n);
	printf("Array before moving duplications: \n");
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nArray after moving duplications: \n");
	answer = moveDuplicatesV2(A, n);
	for (i = 0; i < n; i++) { printf("%d ", A[i]); }
	printf("\nThe number of different elements in array: %d.\n", answer);
	free(A);

}

void Ex4() {
	int n = 0;
	int* A;
	printf("please enter the size of array: \n");
	scanf("%d", &n);
	printf("please enter elements of the array: \n");
	A = input_array(n);
	validateArray(A, n) ? printf("Array contains all numbers from 0 to %d.\n", n - 1) : printf("Array doesn't contain all numbers from 0 to %d.\n", n - 1);
	free(A);
}

/* Sub-Function definitions */

int* input_array(int n) {
	int i;
	int* A = (int*)malloc(n * sizeof(int));
	assert(A);
	printf("Enter %d integers\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", A + i);
	}
	return A;
}

void array_print(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void swap(int* v, int* u)
{
	int temp;
	temp = *v;
	*v = *u;
	*u = temp;
}



int split(int* a, int left, int right)
{
	int i, last = left;
	if (left < right)
	{
		for (i = left + 1; i <= right; i++)
			if (a[i] <= a[left])
				swap(a + (++last), a + i);
		swap(a + left, a + last);
	}
	return last;
}

void quick_sort(int* x, int first, int last)
{
	int pos;
	if (first < last)
	{
		pos = split(x, first, last);
		quick_sort(x, first, pos - 1);
		quick_sort(x, pos + 1, last);
	}
}


int areReversed(int* A, int* B, int n) {
	if (n == 0)
		return 1;
	if (A[0] != B[n - 1])
		return 0;
	return areReversed(A + 1, B, n - 1);
}

int findCommonDigit(unsigned long long n1, unsigned long long n2) {
	if (n1 == 0 || n2 == 0)
		return -1;
	if (n1 % 10 == n2 % 10)
		return n1 % 10;
	if (n1 % 10 > n2 % 10)
		return findCommonDigit(n1 / 10, n2);
	return findCommonDigit(n1, n2 / 10);
}

int binSearch(int key, int* a, int n)
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
int moveDuplicatesV1(int* arr, int n) {
	int* countArray = (int*)calloc(2 * n + 1, sizeof(int));//count array divides left half to negatives
	//and right half to positives 
	int i, offset = 0;
	for (i = 0; i < n; i++) {
		countArray[arr[i] + n]++;
		if (countArray[arr[i] + n] > 1) {// if this number has appeared before
			offset++; // counts the total amount of duplicate numbers
		}
		else if (offset > 0) {
			swap(arr + i, arr + i - offset);
		}
	}
	free(countArray);
	return n - offset;
}

int moveDuplicatesV2(int* arr, int n) {  // solution for all numbers (negative and positive and 0)
	int* duplicateArray = (int*)calloc(2 * n, sizeof(int));// half of the array is for sorted numbers, 
	// half for counting appearances
	int i, offset = 0, k;
	for (i = 0; i < n; i++)
		duplicateArray[i] = arr[i];
	quick_sort(duplicateArray, 0, n - 1);
	for (i = 0; i < n; i++) {
		k = binSearch(arr[i], duplicateArray, n);
		duplicateArray[k + n]++;
		if (duplicateArray[k + n] > 1)
			offset++;
		else if (offset > 0)
			swap(arr + i, arr + i - offset);
	}
	free(duplicateArray);
	return n - offset;
}

int validateArray(int* arr, int n) {
	//assumption: 0<=arr[i]<n
	int i;
	for (i = 0; i < n; i++)
		while (arr[i] != i) {
			if (arr[i] != arr[arr[i]])
				swap(arr + i, arr + arr[i]);
			else
				return 0;
		}
	return 1;
}

/* ------------------- */