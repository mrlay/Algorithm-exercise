#include <stdlib.h>
#include <stdio.h>

int insertion_sort_a(int a[], int n, int k)
{
    int i = 0, j = 0;
    int tmp = 0;
    for(i = 1; i < n; i++) {
        tmp = a[i];
        for(j = i; j > 0 && a[j-1] > tmp; j--){
            a[j] = a[j-1];
        }
        a[j] = tmp;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return a[k];
}

int insertion_sort_b(int a[], int n, int k)
{
    int i = 0, key = 0;
    for(int j = 1; j < n; j++){
        key = a[j];
        i = j -1;
        while(i>=0 && a[i]>key){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return a[k];
}

int insertion_sort_c(int a[], int n, int k)
{
    int i, j, key = 0;
    int b[k+1];
    b[0] = a[0];
    for(i = 1; i < n; i++){
        key = a[i];
        j = i-1;
        if(j < k){
            while(j >= 0 && b[j] > key){
                b[j+1] = b[j];
                j--;
            }
            b[j+1] = key;
        }
        else{
            j=k-1;
            if(b[j] > key){
                while(j >= 0 && b[j] > key){
                    b[j+1] = b[j];
                    j--;
                }
                b[j+1] = key;
            }
        }
    }

    for(int i = 0; i < k+1; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return b[k];

}

int insertion_sort_d(int a[], int n, int k)
{
    int i, j, key = 0;
    for(i = 1; i < n; i++){
        key = a[i];
        j = i--;
        if(i < k){
            while(j >= 0 && a[j] > key){
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = key;
        }
        else{
            j=k-1;
            if(a[j] > key){
                while(j >= 0 && a[j] > key){
                    a[j+1] = a[j];
                    j--;
                }
                a[j+1] = key;
            }
        }
    }

}


int main(int argc, char **argv)
{
    int iRet = 0;
    int a[17] = {23,-67,2,56,-4,89,-49,2,-1,3,4,-89,71,33,-31,54,9};
    int b[17] = {23,-67,2,56,-4,89,-49,2,-1,3,4,-89,71,33,-31,54,9};

    printf("before: \n");
    for(int i = 0; i < 17; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("the 8th is: %d\n", insertion_sort_a(a, 17, 8));

    printf("before: \n");
    for(int i = 0; i < 17; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("the 8th is: %d\n", insertion_sort_c(b, 17, 8));

    return iRet;
}
