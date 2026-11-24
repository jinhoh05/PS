#include <bits/stdc++.h>

using namespace std;
using pii=pair<int,int>;

int n,s;
pii pic[300005];
int DP[300005];

int dynamic(){
    int j=0;
    for(int i=1;i<=n;i++){
        DP[i]=DP[i-1];
        while(pic[j+1].first + s <= pic[i].first) j++;
        DP[i]=max(DP[i],DP[j]+pic[i].second);
    }
    return DP[n];
}

int main()
{
    scanf("%d %d",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&pic[i].first,&pic[i].second);
    }
    sort(pic+1,pic+n+1);

    printf("%d",dynamic());

    return 0;
}