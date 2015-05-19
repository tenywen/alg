#include <stdio.h>

int main() {
    int p[31] = {0,1,5,8,9,10,17,17,20,24,30};  
    int cost =  2;
    int i,j;
    int max;
    int value;
    for(i = 1; i <= 30; i ++ ) {
        max = p[i];
        for (j = 1; j <= i; j ++) {
            value = p[j] + p[i - j];
            if(i - j != 0) {
                value -= cost; 
            } 
            if(value > max) {
                max = value; 
            } 
        }
        p[i] = max;
    }
    for(i = 1; i <= 30; i ++) {
        printf("%d -> %d\n",i,p[i]); 
    }
}
