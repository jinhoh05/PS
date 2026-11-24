#include <bits/stdc++.h>

using namespace std;
int n,ans,DP[105];

struct data{
    int a,b;
    bool operator<(const data&t)const{
        return a<t.a;
    }

}elec[105];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&elec[i].a,&elec[i].b);
    }
    sort(elec+1,elec+n+1);

    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            if(elec[i].b < elec[j].b) DP[i]=max(DP[i],DP[j]+1);
        }
    }

    for(int i=1;i<=n;i++){
        ans=max(ans,DP[i]);
    }

    printf("%d",n-ans-1);

    return 0;
}