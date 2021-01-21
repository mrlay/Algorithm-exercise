#include <stdlib.h>
#include <stdio.h>

int select_sort(int a[], int n, int k)
{
    int tmp = 0;
    for(int i = 1; i < n; i++) {
        tmp = a[i-1];
        for(int j = i; j > 0; j--){
            if(a[j] < tmp){
                a[j] = a[j-1];
            }
            else{
                a[j] = tmp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return a[k];
}



int main(int argc, char **argv)
{
    int iRet = 0;


}
