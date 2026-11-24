#include <iostream>
#include <stdio.h>
#include <string.h>
char cnt[100000];
int mx=0;
using namespace std;

int change(int x,int y){

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
    int n,b;
    scanf("%d", &n);
    scanf("%d", &b);
    change(n,b);

    return 0;
}