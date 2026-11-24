#include <bits/stdc++.h>

using namespace std;
int n,DP[500005],cnt,vt[500005],path[500005],ans[500005],sum;

struct data{
    int a,b;
    bool operator<(const data&t)const{
        return b<t.b;
    }

}elec[500005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&elec[i].a,&elec[i].b);
    }
    sort(elec+1,elec+n+1);

    for(int i=1;i<=n;i++){
        int temp=lower_bound(&DP[0],&DP[cnt],elec[i].a)-&DP[0];

        if(cnt==temp){
            DP[cnt++]=elec[i].a;
            path[sum++]=cnt;
        }
        else{
            path[sum++]=temp+1;
            DP[temp]=elec[i].a;
        }
    }

    printf("%d\n",n-cnt);

    for(int i=n-1;i>=0;i--){
        if(path[i]==cnt){
            vt[elec[i+1].a]=1;
            cnt--;
        }
        if(cnt==0) break;
    }

    for(int i=1;i<=n;i++){
        if(vt[elec[i].a]==0) ans[++cnt]=elec[i].a;
    }

    sort(ans+1,ans+cnt+1);

    for(int i=1;i<=cnt;i++) printf("%d\n",ans[i]);


    return 0;
}