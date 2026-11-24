#include <bits/stdc++.h>

using namespace std;
int n,num[10],binary[10];

void put(){
    binary[1]=1;
    for(int i=2;i<=8;i++){
        binary[i]=binary[i-1]*2;
    }
}

void change(void){
    for(int i=1;i<=8;i++){
        num[i]=1-num[i];
    }
}

int res(int a){
    int sum=0;

    for(int i=1;i<=8;i++){
        if(num[9-i]==1) sum+=binary[i];
    }

    if(a==1) sum=0-(sum+1);

    return sum;
}

int main()
{
    scanf("%d",&n);

    for(int i=8;n>=1;i--){
        num[i]=n%10;
        n=n/10;
    }

    put();

    if(num[1]==1){
        change();
        printf("%d",res(1));
    }

    else printf("%d",res(0));

    return 0;
}