#include <bits/stdc++.h>

using namespace std;
int n,m,cnt,hap,ans;
int notprime[10005];

void eratos(){
    notprime[1]=1;
    for(int i=2;i*i<=10000;i++){
        if(notprime[i]==0){
            for(int j=i*i;j<=10000;j+=i){
                notprime[j]=1;
            }
        }
    }

}

int main()
{
    scanf("%d %d",&n,&m);

    eratos();

    for(int i=n;i<=m;i++){
        if(notprime[i]==0){
            cnt++;
            hap+=i;
            if(cnt==1) ans=i;
        }
    }
    
    if(cnt==0) printf("-1");
    else printf("%d\n%d",hap,ans);

    return 0;
}