#include <stdio.h> 
#include <string.h>
// 最长公共子序列 
int main() {
    char b[] = {"aaa"}; 
    char a[] = {"abcdefghijk"}; 
    int  c[11][11] = {0};
    int i,j;
    int a1,a2,a3;
    int m;
    for(i = 0; i < strlen(a); i ++)  {
        for(j = 0; j < strlen(b); j ++) { 
            if(i < 1 || j < 1) {
                a1 = 0;
                a2 = 0;
                a3 = 0;
            } else {
                a1 = c[i - 1][j];
                a2 = c[i][j - 1];
                a3 = c[i-1][j-1];
            }
            if(a[i] == b[j]) {
                a1 += 1; 
            }
            if(a[i] == b[j]) {
                a2 += 1; 
            }
            if(a[i] == b[j]) {
                a3 += 1; 
            }
            m = a1;
            if(m < a2) {
                m = a2; 
            }  
            if (m < a3) {
                m = a3; 
            }
            c[i][j] = m;
        }
    }

    for(i = 0;i < 11; i++) {
        for(j = 0;j < 11; j ++) {
            printf("c[%d][%d]= %d\n",i,j,c[i][j]);
        }
            
    }
}
