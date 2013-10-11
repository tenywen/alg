/*******************************************
   
   
   				@ quicksort	
   				@ nlgn
		

********************************************/
#include <stdio.h>

int APartition(int *A,int p,int r) {
	int x = A[p];
	// 必须保证从第p + 1开始
	int i = p + 1;
	int j = r;
	int tmp = 0;
	for (; i < j; ) {
		// 关注此循环，此循环保证[0,i]比x小
		while(A[i] <= x && i < j) {
			i ++;	
		}
		while(A[j] >= x && i < j) {
			j --;		
		}
		if (i < j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}	
	}
	A[p] = A[i - 1];
	A[i - 1] = x;
	return i;
}

int BPartition(int *A, int p,int r) {
	int x = A[r];
	int i = p - 1;
	int j = p;
	int tmp = 0;
	for (; j < r; j ++) {
		// 只关注比A[r]小的
		// [p,i] 都是比x小的
		// i+1则是大于x的
		// 比x小，则交换
		// 比x大，则不懂
		if (A[j] < x) {
			i = i + 1;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	A[r] = A[i + 1];
	A[i + 1] = x;
	return i + 1;
}

int main() {
	int A[] = {9,3,4,3,2,23,117,7,14,45};
	int i = 0;
	printf("\n");
	for (i = 0; i < 10; i ++) {
		printf("%d ",A[i]);
	}
	//APartition(A,0,9);
	BPartition(A,0,9);
	printf("\n");	
	for (i = 0; i < 10; i ++) {
		printf("%d ",A[i]);
	}
}

