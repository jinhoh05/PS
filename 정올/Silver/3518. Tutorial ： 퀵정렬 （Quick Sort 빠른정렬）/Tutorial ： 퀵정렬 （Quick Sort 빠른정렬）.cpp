#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void quickSort(int A[],int low,int high){
    int i,j;
    int pivot;

    if (low < high) {
        i = low-1;
        pivot = A[high];

        for(j=low;j<high;j++){
            if(A[j] < pivot){
                swap(A[++i], A[j]);
            }
        }

        swap(A[++i], A[high]);

        for(int f=0;f<n;f++){
            printf("%d ",A[f]);
        }

        printf("\n");

        quickSort(A, low, i-1);
        quickSort(A, i+1, high);
    }
}

int main()
{
    int A[1005];
    scanf("%d",&n);
    for(int f=0;f<n;f++){
        scanf("%d",&A[f]);
    }

    quickSort(A,0,n-1);

    return 0;
}