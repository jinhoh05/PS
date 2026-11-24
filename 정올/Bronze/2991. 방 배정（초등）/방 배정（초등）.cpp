#include <bits/stdc++.h>

using namespace std;
int n,k,g,b,ans_g,ans_b;
int boy[7],girl[7];


int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&g,&b);
        if(g==0) girl[b]++;
        else boy[b]++;
    }

    for(int i=1;i<=6;i++){
        ans_g+=girl[i]/k;
        if(girl[i]%k > 0) ans_g++;

        ans_b+=boy[i]/k;
        if(boy[i]%k > 0) ans_b++;
    }

    printf("%d",ans_g+ans_b);
    return 0;
}