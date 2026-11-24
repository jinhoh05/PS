#include <bits/stdc++.h>

using namespace std;
int n,num[1005],ans_b,ans_s=100000,small,big;
int vt[26][26];

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
        big=small=num[i];
        ans_b=max(ans_b,big);
        ans_s=min(ans_s,small);
    }

    printf("%d",ans_b-ans_s);

    return 0;
}