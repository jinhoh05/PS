#include <bits/stdc++.h>

using namespace std;

int n,cnt=0,len;
set<int> ans;

void dfs(int a,int b,int d){
    if(a < 10){
        ans.insert(a*d+b);
        return;
    }

    for(int i=0;i<=9;i++){
        int t=a-i;
        if(t < 10) break;
        if(t%10 == i) dfs(t/10,i*d+b,d*10);
        else if(t % 11 == 0) ans.insert((t/11*10+i)*d+b);
    }
}

int main()
{
    scanf("%d",&n);

    dfs(n,0,1);

    printf("%d\n",ans.size());

    for(auto i:ans){
        printf("%d + %0*d = %d\n",i,(int)log10(i),n-i,n);
    }

    return 0;
}