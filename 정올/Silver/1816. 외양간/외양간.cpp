#include <bits/stdc++.h>

using namespace std;
int m,s,c;
int vt[205];
int cw[205];
int ans;

int fin(){
    int big=0;

    for(int i=1;i<=c;i++){
        if(vt[i]) continue;
        if(cw[i] - cw[i-1] - 1 > big) big=cw[i] - cw[i-1] - 1;
    }

    for(int i=1;i<=c;i++){
        if(vt[i]) continue;
        if(cw[i] - cw[i-1] - 1== big){
            vt[i]=1;
            break;
        }
    }

    ans-=big;

    return 0;
}


int main()
{

    scanf("%d %d %d",&m,&s,&c);
    for(int i=1;i<=c;i++){
        scanf("%d",&cw[i]);
    }

    sort(cw,cw+c+1);

    cw[0]=cw[1];

    ans=cw[c]-cw[1]+1;

    for(int i=1;i<m;i++){
        fin();
    }

    printf("%d",ans);
    return 0;
}