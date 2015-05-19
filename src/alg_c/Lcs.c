/*******************************************
 
      		@ lcs 
            @ char 
			@ complete lcs
						
********************************************/
#include <stdio.h>
#include <string.h>
#include "Lcs.h"

#define LENGTH 256
char* LCS(const char *a,const char *b) {
	char *p	= (char*)malloc(sizeof(char) * LENGTH);
	if (p == NULL) {
		printf("malloc error\n");
		return NULL;
	}
	_lcs(a,strlen(a),b,strlen(b),p);
	return p;	
}

int _lcs(const char *a,int len_a,const char *b,int len_b,char *p) {
	if(len_a < 0 || len_b < 0) 
		return 0;
	if(a[len_a - 1] == b[len_b - 1]) {
		_lcs	
	}
	return 0;
}
