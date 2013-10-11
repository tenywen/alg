/*******************************************
   
   
   				@ heapsort	
   				@ max heap	
		

********************************************/
// 长度为n的堆，则从[n/2] + 1,n开始都是叶子节点 [n/2]向下取整
// n元素的堆的高度为[lgn] [lgn]向下取整
// 高度为h的堆，其元素个数在[2^(h-1),2^h]之间
#include <stdio.h>

#define PARENT(i) (i>>1)
#define LEFT(i) (i<<1)
#define RIGHT(i) ((i<<1) + 1)

// 使以i为根的子树，保持max heap性质 下沉
int MaxHeapify() {
		
}

int BuildHeap() {
	
}

int main() {
	return 0;
}
