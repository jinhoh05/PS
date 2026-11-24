#include <bits/stdc++.h>

using namespace std;
int n,m,t,k;
int ans, ax,ay;

vector<pair<int,int>> st;

void counting(int x,int y){
    int cnt=0, ex=x+k,ey=y+k;
    for(auto&a : st){
        int r=a.first,c=a.second;
        if(r>=x && r<= ex && c >= y && c<=ey) cnt++;
    }
    if(ans < cnt){
        ans=cnt;
        ax=x;
        ay=ey;
    }
}

int main()
{
//    freopen("input.txt","r",stdin);

    int x,y;
    scanf("%d %d %d %d",&n,&m,&t,&k);
    for(int i=1;i<=t;i++){
        scanf("%d %d",&x,&y);
        st.push_back({x,y});
    }

    for(int i=0;i<t;i++){
        for(int j=i+1;j<=t;j++){
            x=min(st[i].first,st[j].first);
            y=min(st[i].second,st[j].second);
            counting(x,y);
        }
    }

    printf("%d %d\n%d",ax,ay,ans);
    return 0;
}