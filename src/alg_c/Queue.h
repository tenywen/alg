/*******************************************
   
   
   				@ Queue 
				@ int loop array 
				@ Queue.h
						

********************************************/
#ifndef _QUEUE_H_
#define _QUEUE_H_
#define QUEUE_MAX	256		// 队列中最大个数

#include "common.h"

struct Queue {
	int array[QUEUE_MAX + 1];
	int tail;
	int head;		
}; 


extern Queue* QueueNew();
extern bool QueuePush(Queue* p,int x);
extern int QueuePop(Queue* p, ERROR* err);
extern bool QueueEmpty(Queue* p);
extern bool QueueFull(Queue* p);
#endif
