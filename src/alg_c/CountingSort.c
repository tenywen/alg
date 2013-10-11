/*******************************************
   
   
   				@ counting sort	
   				@ n
		

********************************************/
#include <stdio.h>
#include <string.h>

int CountingSort(int *A,int *B,int len) {
	int C[4] = {0};
	int i = 0;
	for (i = 0; i < len; i ++) {
		C[A[i]] += 1;
	}
	for (i = 1; i < 4; i ++) {
		C[i] = C[i] + C[i - 1];
	}
	for (i = len - 1; i >= 0; i --) {
		B[C[A[i]]] = A[i];
		C[A[i]] -= 1;
	}
	return 0;
}

int main() {
	int A[] = {1,2,3,3,3};
	int* B = (int*)malloc(sizeof(int) * 5);
	int i = 0;
	CountingSort(A,B,5);
	for (i = 0; i < 5; i ++) {
		printf("\n");
		printf("%d ",B[i]);		
	}
}
