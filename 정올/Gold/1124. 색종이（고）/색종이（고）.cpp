#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n,ans,mx;
int x,y,s[105][105],w[105],stk[105];


void check(){
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(s[i][j] == 1) s[i][j]+=s[i-1][j]; 
        }
    }
}   

void histogram(int i){
    int cnt=0;
    int sum=0;
    
    for(int j=1;j<=100;j++){
        sum=0;
        while(cnt > 0 && stk[cnt-1] >= s[i][j]){
           sum+=w[cnt-1];
            if(ans < stk[cnt-1] * sum) ans=stk[cnt-1] * sum;
            cnt--;
        }
        stk[cnt]=s[i][j];
        w[cnt++]=sum+1;
    
    }

    sum=0;
    
    while(cnt > 0){
        sum+=w[cnt-1];
        if(ans < stk[cnt-1] * sum) ans=stk[cnt-1] * sum;
        cnt--;
    }
}
int main()
{
    
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        for(int i=x;i<x+10;i++){
            for(int j=y;j<y+10;j++){
                s[i][j]=1;
            }
        }
    }
    
    check();
    
    /*for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            printf("%2d ",s[i][j]);
        }
        printf("\n");
    }*/
    
    for(int i=1;i<=100;i++){
        histogram(i);
    }
    
    printf("%d",ans);
    
    return 0;
}