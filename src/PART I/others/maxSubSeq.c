#include<stdio.h>
#include<stdlib.h>

#define MAX(a, b) (a) > (b) ? (a) :(b)
#define MAX3(a, b, c) (a) > (b) ? ((a) > (c) ? (a) : (c)) :((b) > (c) ? (b) : (c))


int maxSubSeqSum_n3(int a[], int n)
{
    int thisSum = 0, maxSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            thisSum = 0;
            for(int k = i; k <= j; k++){
                thisSum += a[k];
            }
            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}


int maxSubSeqSum_n2(int a[], int n)
{
    int thisSum = 0, maxSum = 0;
    for(int i = 0; i < n; i++){
        thisSum = 0;
        for(int j = i; j < n; j++){
            thisSum += a[j];

            if(thisSum > maxSum){
                maxSum = thisSum;
            }
        }
    }

    return maxSum;
}

int maxSubSeqSum_recusive(int a[], int l, int r)
{
    int leftMax = 0, rightMax = 0, lc = 0, rc = 0, c = 0;
    int lcMax = 0, rcMax = 0, cMax = 0;
    int lTmp = 0, rTmp = 0;

    if(l == r){
        if(a[l] > 0)
            return a[l];
        else
            return 0;
    }
    c = (l + r)/2;
    leftMax = maxSubSeqSum_recusive(a, l, c);
    rightMax = maxSubSeqSum_recusive(a, c+1, r);

    for(int i = c; i >= l; i--){
        lTmp += a[i];

        if(lTmp > lcMax)
            lcMax = lTmp;
    }

    for(int i = c+1; i <= r; i++){
        rTmp += a[i];

        if(rTmp > rcMax)
            rcMax = rTmp;
    }


    return MAX3(leftMax, rightMax, rcMax+lcMax);
}

int maxSubSeqSum_nlogn(int a[], int n)
{
    return maxSubSeqSum_recusive(a, 0, n-1);
}

int maxSubSeqSum_n(int a[], int n)
{
    int maxSum = 0, thisSum = 0;
    for(int i = 0; i < n; i++){
        thisSum += a[i];

        if(thisSum > maxSum){
            maxSum = thisSum;
        }

        if(thisSum < 0){
            thisSum = 0;
        }
    }

    return maxSum;

}

int main(int argc, char **argv)
{
    int a[] = {123,23,-67,2,56,-4,89,-49,2,-1,3,4,-89,71,33,-31,54,9};
    int n = 18;

    printf("maxSubSeqSum_n3 : %d\n", maxSubSeqSum_n3(a, n));
    printf("maxSubSeqSum_n2 : %d\n", maxSubSeqSum_n2(a, n));
    printf("maxSubSeqSum_nlogn : %d\n", maxSubSeqSum_nlogn(a, n));
    printf("maxSubSeqSum_n : %d\n", maxSubSeqSum_n(a, n));

    return 0;
}
