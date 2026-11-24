#include <bits/stdc++.h>

using namespace std;
int n,k,ans,room_g[4],room_b[4],p,vt[55];

int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(b==1||b==2) room_g[1]++;
        else if(b==3||b==4){
            if(a==0) room_g[2]++;
            else room_b[2]++;
        }
        else{
            if(a==0) room_g[3]++;
            else room_b[3]++;
        }
    }

    for(int i=1;i<=3;i++){
        if(room_g[i]%k>0) ans+=room_g[i]/k+1;
        else ans+=room_g[i]/k;

        if(room_b[i]%k>0) ans+=room_b[i]/k+1;
        else ans+=room_b[i]/k;
    }

    printf("%d",ans);
    return 0;
}