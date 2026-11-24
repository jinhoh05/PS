#include <bits/stdc++.h>

using namespace std;
int n,m,seat[45],s,fibo[45];
long long int ans=1;
int main()
{
    int cnt=0;

    scanf("%d %d",&n,&m);


    for(int i=1;i<=m;i++){
        scanf("%d",&s);
        seat[s]=1;
    }


    fibo[1]=fibo[0]=1;

    for(int i=2;i<=n;i++){
        fibo[i]=fibo[i-1] + fibo[i-2];
    }

    for(int i=1;i<=n;i++){
        if(seat[i] == 0){
            cnt++;
        }
        else{
            ans*=fibo[cnt];
            cnt=0;
        }
    }

    printf("%d",ans*fibo[cnt]);


    return 0;
}
/*
15
3
3
4
7
*/