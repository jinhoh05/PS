#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,mx,xm;
int bishop[15][15],l[30],r[30],chk[30];
int A[15],used[15];
 
//짝수
void prting(int num,int ans,int b){
    int lev=b,cnt=0;
 
    if(b > n){
        if(ans > xm) xm=ans;
        return;
    }
 
    for(int i=1;i<=num;i++){
        if(bishop[lev][i] == 1 && l[i+lev] == 0 && r[i-lev+4] == 0){
            l[i+lev]=1;
            r[i-lev+4]=1;
            prting(num-2,ans+1,b+2);
            l[i+lev]=0;
            r[i-lev+4]=0;
        }
        else cnt++;
 
        if(cnt == num) prting(num-2,ans,b+2);
        lev++;
    }
 
}
 
void prt(int num,int ans,int b){
    int lev=b,cnt=0;
 
    if(b > n){
        prting(n-1,ans,2);
        return;
    }
 
    for(int i=1;i<=num;i++){
        if(bishop[i][lev] == 1 && l[i+lev] == 0 && r[lev-i+4] == 0){
            l[i+lev]=1;
            r[lev-i+4]=1;
            prt(num-2,ans+1,b+2);
            l[i+lev]=0;
            r[lev-i+4]=0;
        }
        else cnt++;
 
        if(cnt == num) prt(num-2,ans,b+2);
        lev++;
    }
 
}
 
//홄수
void permuting(int num,int ans,int b){
    int lev=b,cnt=0;
 
    if(b > n){
        if(ans > mx) mx=ans;
        return;
    }
 
    for(int i=1;i<=num;i++){
        if(bishop[lev][i] == 1 && l[i+lev] == 0 && r[i-lev+4] == 0){
            l[i+lev]=1;
            r[i-lev+4]=1;
            permuting(num-2,ans+1,b+2);
            l[i+lev]=0;
            r[i-lev+4]=0;
        }
        else cnt++;
 
        if(cnt == num) permuting(num-2,ans,b+2);
        lev++;
    }
 
}
 
void permut(int num,int ans,int b){
    int lev=b,cnt=0;
 
    if(b > n){
        permuting(n-1,ans,3);
        return;
    }
 
    for(int i=1;i<=num;i++){
        if(bishop[i][lev] == 1 && l[i+lev] == 0 && r[lev-i+4] == 0){
            l[i+lev]=1;
            r[lev-i+4]=1;
            permut(num-2,ans+1,b+2);
            l[i+lev]=0;
            r[lev-i+4]=0;
        }
        else cnt++;
 
        if(cnt == num) permut(num-2,ans,b+2);
        lev++;
    }
 
}
 
int main()
{
 
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&bishop[i][j]);
        }
    }
 
    permut(n,0,1);
    prt(n,0,2);
 
    printf("%d",mx+xm);
    return 0;
}