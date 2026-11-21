#include <bits/stdc++.h>
 
using namespace std;
int n,q;
int jump[100005];
 
struct da{
 
    int x1,x2,lev;
 
}frog[100005];
 
bool comp(const da&a,const da&b){
    return a.x1 < b.x1;
}
 
int main()
{
 
    scanf("%d %d",&n,&q);
 
    for(int i=1;i<=n;i++){
        scanf("%d %d %*d",&frog[i].x1,&frog[i].x2);
        frog[i].lev=i;
    }
 
    sort(frog+1,frog+n+1,comp);
 
    int cnt=1,fr;
 
    jump[frog[1].lev]=cnt;
    fr=frog[1].x2;
 
    for(int i=2;i<=n;i++){
        if(fr < frog[i].x1) cnt++;
        if(fr < frog[i].x2) fr=frog[i].x2;
        jump[frog[i].lev]=cnt;
    }
 
    int y1,y2,sum;
    for(int i=1;i<=q;i++){
        scanf("%d %d",&y1,&y2);
 
        if(jump[y1] == jump[y2]) printf("1\n");
        else printf("0\n");
    }
 
    return 0;
}