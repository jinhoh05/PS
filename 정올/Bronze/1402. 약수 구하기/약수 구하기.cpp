#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int s[41];
    int n,m;
    int cnt=1;
    int a[5000]={0};
    int k;
    scanf("%d %d",&n, &k);


    for(int j=1;j<=n;j++){
        if(n % j == 0){
            a[cnt] = j;
            cnt++;
        }
    }
    if(a[k] != 0){
        printf("%d",a[k]);
    }
    else{
        printf("0");
        
    }
   
    return 0;
}