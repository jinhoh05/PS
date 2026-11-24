#include <iostream>

using namespace std;
int n;
void merge(int a[],int b[],int c[],int al, int bl){

    int i=0,j=0;
    while(i<al && j<bl){
        if(a[i] < b[j]){
            c[i+j]=a[i];
            i++;
        }
        else{
            c[i+j]=b[j];
            j++;
        }
    }

    while(i < al){
        c[i+j]=a[i];
        i++;
    }

    while(j < bl){
        c[i+j]=b[j];
        j++;
    }
}

void copy(int a[],int b[],int len){

    for(int i=0;i<len;i++){
        a[i]=b[i];
    }
}

int tmp[1005];
void mergeSort(int A[],int low,int high) {
    if(low < high){
        int mid = (low+high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A,mid+1,high);
        merge(A+low,A+mid+1,tmp,mid-low+1,high-mid);
        copy(A+low,tmp,high-low+1);
        for(int i=0;i<n;i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }
}

int main()
{
    int a[1005];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    return 0;
}