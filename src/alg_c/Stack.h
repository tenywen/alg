/*******************************************
   
   
   				@ stack 
				@ int array
				@ stack.h
						

********************************************/
#ifndef _STACK_H_
#define _STACK_H_
#define STACK_MAX 256		// 栈元素最大个数 栈空间为256 * 4 = 1K
#include "common.h"

struct Stack {
	int array[STACK_MAX];
	int size;
	int length;
};

extern bool StackEmpty(Stack* p);
extern bool StackPush(Stack* p,int x);
extern int StackPop(Stack* p,ERROR* error);
extern Stack* StackNew();

#endif
