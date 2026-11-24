#include <iostream>
#include <stdio.h>
#include <string.h>
char cnt[100000];


using namespace std;


long long change1(int x,char y[]){
    long long d=0;
    int mx=strlen(y);
    for(int i=0;i<mx;i++){
        if(y[i] >= 'A'){
            d=d * x + y[i] - 'A' + 10;
        }
        else d=d * x + y[i] - '0';
    }
    return d;
}


int change(long long x,int y){
    int mx=0;
    while(x > 0){
        int d=x % y;
        if(d >= 10){
            cnt[mx]= 'A' + d - 10;
        }
        else cnt[mx] = d + '0';
        x=x/y;
        mx++;
    }
    for(int i=mx-1;i>=0;i--){
        printf("%c",cnt[i]);
    }
}


int main()
{
    int a,b;
    long long t;
    char n[65];
    for(int i=0;;i++){
        scanf("%d", &a);
        if(a==0) break;
        scanf("%s", n);
        scanf("%d", &b);

        t=change1(a,n);
        if(t == 0) printf("0");
        else {
            change(t,b);
        }
        printf("\n");

    }
    return 0;
}