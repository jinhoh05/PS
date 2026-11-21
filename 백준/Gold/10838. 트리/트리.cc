#include <bits/stdc++.h>
 
using namespace std;
int n,k,lev,vt[100010];
int A[100010],color[100010],cvt[100010],tree[100010]={-1};
 
int track(int a,int b){
    lev++;
    for(int i=0;i<=1000 && a >= 0;i++){
        vt[a]=lev;
        a=tree[a];
    }
    while(vt[b] != lev) b=tree[b];
 
    return b;
}
 
void paint(int a,int b,int c){
    int root = track(a,b);
 
    while(a != root){
        color[a] = c;
        a=tree[a];
    }
 
    while(b != root){
        color[b] = c;
        b=tree[b];
    }
}
 
int count(int a,int b){
    int root = track(a,b);
    int cnt=0;
 
    while(a != root){
        A[cnt++]=color[a];
        a=tree[a];
    }
 
    while(b != root){
        A[cnt++]=color[b];
        b=tree[b];
    }
 
    sort(A,A+cnt);
    cnt=unique(A,A+cnt) - A;
 
    return cnt;
}
 
int main()
{
    scanf("%d %d",&n,&k);
 
    for(int i=1;i<=k;i++){
        int r,a,b,c;
        scanf("%d %d %d",&r,&a,&b);
 
        if(r==1){
            scanf("%d",&c);
            paint(a,b,c);
        }
 
        else if(r==2) tree[a]=b;
 
        else printf("%d\n",count(a,b));
    }
 
    return 0;
}