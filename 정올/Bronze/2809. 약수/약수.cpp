#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
     int sq;
     int arr[10000], cnt=0;
     int N;
     int i;
     scanf("%d",&N);
     for (i = 1; i * i <= N; i++) {
         if (N % i == 0) {
             printf("%d ",i);
             if (N / i != i){
                arr[cnt++] = N / i;
             }
         }
     }


     for (i = cnt-1;i >= 0;i--){

             printf("%d ",arr[i]);
     }


   return 0;
}