#include <bits/stdc++.h>

using namespace std;
int n,m,l,k,c,ans,p,vt[1005][1005],shot_p[100005],cnt=1;
struct data{
    int x,y;
    bool operator<(const data&t)const{
        if(x==t.x) return y<t.y;
        return x<t.x;
    }
}animal[100005];

int main()
{
    scanf("%d %d %d",&m,&n,&l);
    for(int i=1;i<=m;i++){
        scanf("%d",&shot_p[i]);
    }
    sort(shot_p+1,shot_p+m+1);

    for(int i=1;i<=n;i++){
        scanf("%d %d",&animal[i].x,&animal[i].y);
    }
    sort(animal+1,animal+n+1);

    int j=1;
    for(int i=1;i<=n;i++){
        while(j<=m && shot_p[j] < animal[i].x) j++;
        int sh=shot_p[j],x=animal[i].x,y=animal[i].y;
        if(j > 1 && abs(shot_p[j-1]-x)+y <= l || j <= m && abs(sh-animal[i].x)+y <= l) ans++;
    }

    printf("%d",ans);

    return 0;
}