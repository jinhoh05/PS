#include <bits/stdc++.h>

using namespace std;
int n,square[100005],ans,big,num;
int vt[26][26];

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&square[i]);
    }

    for(int i=n;i>=1;i--){
        if(square[i] > big){
            big=square[i];
            ans++;
        }
    }

    printf("%d",ans);

    return 0;
}