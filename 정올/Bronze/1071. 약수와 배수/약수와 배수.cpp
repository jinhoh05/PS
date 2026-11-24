#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int s[41];
    int n,m;
    int cnt=0;
    int a[50];
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }

    scanf("%d",&m);

    for(int j=1;j<=m;j++){
        if(m % j == 0){
            a[cnt] = j;
            cnt++;
        }
    }
    int sum=0;
    for(int j=0;j<cnt;j++){
        for(int i=0;i<n;i++){
            if(s[i] == a[j]){
              sum+=a[j];
            }
        }
    }

    printf("%d\n",sum);
    sum=0;

    for(int i=0;i<n;i++){
        if(s[i] % m == 0){
          sum+=s[i];
        }
    }

    printf("%d\n",sum);



    return 0;
}