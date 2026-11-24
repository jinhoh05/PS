#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,sum=0;
int number[3][105];
int ans[105];
int cnt=1;
int org=0;
int maxl=1;
int num=0;
int co=0;

int put(int cnt){
    ans[maxl]=org;

    for(int i=maxl+1;i<=maxl+cnt;i++){
        ans[maxl]=number[1][num];
        num=number[2][num];
    }

    return 0;
}

void search(int sum){
    cnt++;
    if(org == number[2][sum]){
        put(cnt);
        maxl+=cnt;
        cnt=1;
        return;
    }

    if(cnt > n){
        cnt=1;
        return;
    }

    search(number[2][sum]);
}

int check(){

    for(int i=1;i<=n;i++){
        org=number[1][i];
        num=number[2][i];
        search(number[2][i]);
    }

    sort(ans+1, ans+maxl+1);

    for(int i=1;i<=maxl;i++){
        if(ans[i] == 0) co++;
    }

    printf("%d\n",maxl-co);

    for(int i=1;i<=maxl;i++){
        if(ans[i] == 0) continue;
        printf("%d\n",ans[i]);
    }
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        number[1][i]=i;
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&number[2][i]);
    }

    check();

    return 0;
}