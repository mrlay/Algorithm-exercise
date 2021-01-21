#include <cstdlib>
#include <stdio.h>
#include <time.h>

void rand_a(int a[], int n)
{
    int s = 0;
    int r = 0;
    srand((unsigned)time(NULL));
    r= rand() % n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(r == a[j]){
                s = 1;
                break;
            }
        }

        if(s){
            r= rand() % n;
            i--;
            s = 0;
        }
        else{
            a[i] = r;
        }
    }
}

void rand_b(int a[], int b[], int n)
{
    int s = 0;
    int r = 0;
    srand((unsigned)time(NULL));
    r= rand() % n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(r == b[j]){
                s = 1;
                break;
            }
        }

        if(s){
            r= rand() % n;
            i--;
            s = 0;
        }
        else{
            a[i] = r;
        }
    }
}
