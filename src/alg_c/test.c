#include <stdio.h>
#include "common.h"
#include "Stack.h"
int main() {
	Stack* p = StackNew();
	int a = 0;
	printf("%p\n",p);
	printf("%d",FLOOR(a));
	printf("%d",CEIL(a));
	return 0;	
}
