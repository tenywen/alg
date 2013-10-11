/*******************************************
   
   
   				@ Queue 
				@ int loop array 
				@ complete
						

********************************************/
#include "common.h"
#include <stdlib.h>
#include "Queue.h"

Queue* QueueNew() {
	Queue* p = (Queue*)malloc(sizeof(Queue));
	if (p != NULL) {
		p->tail = p->head = 0;		
	}
	return p;
}

bool QueueEmpty(Queue* p) {
	return (p->tail == p->head) ? true : false;
}

bool QueueFull(Queue* p) {
	int tail = (p->tail + 1) % QUEUE_MAX;
	return (tail == p->head) ? true : false;	
}

bool QueuePush(Queue* p,int x) {
	if (QueueFull(p)) {
		return false;		
	}
	p->array[p->tail] = x;
	int tail = (p->tail + 1) % QUEUE_MAX;
	p->tail = tail;
	return true;
}

int QueuePop(Queue* p, ERROR* err) {
	int result = 0;
	if (QueueEmpty(p)) {
		*err = EMPTY;		
		return 0;
	}
	result = p->array[p->head];
	int head = (p->head + 1) % QUEUE_MAX;
	p->head = head;
	return result;
}

