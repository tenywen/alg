/*******************************************
   
   
   				@ stack 
				@ int array
				@ complete 
						

********************************************/
#include <stdlib.h>
#include "Stack.h"
#include "common.h"
Stack* StackNew() {
	Stack *p = (Stack*)malloc(sizeof(Stack));
	if (p != NULL) {
		p->size = STACK_MAX;
		p->length = 0;
	}
	return p;
}

bool StackPush(Stack* p,int x) {
	if(p->length == p->size) {
		return false;
	}

	p->array[p->length] = x;
	p->length ++;
	return true;
}

int StackPop(Stack* p,ERROR* err) {
	int result = 0;
	if (p->length == 0 ) {
		*err = EMPTY;
		return result;
	}
	result = p->array[p->length - 1];
	p->length --;
	return result;	
}
