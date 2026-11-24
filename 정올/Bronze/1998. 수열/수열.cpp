#include <bits/stdc++.h>

using namespace std;
int n,big,small,ans_b,ans_s=0;
int num[100005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }

    if(n==1){
        printf("1");
        return 0;
    }

    for(int i=2;i<=n+1;i++){
        if(num[i] >= num[i-1]) big++;
        else{
            ans_b=max(ans_b,big+1);
            big=0;
        }
    }

    for(int i=2;i<=n+1;i++){
        if(num[i] <= num[i-1]) small++;
        else{
            ans_s=max(ans_s,small+1);
            small=0;
        }
    }
    ans_s=max(ans_s,small);
        
    printf("%d",ans_b > ans_s ? ans_b : ans_s);
    return 0;
}