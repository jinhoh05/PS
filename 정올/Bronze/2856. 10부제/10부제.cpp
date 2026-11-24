#include <bits/stdc++.h>

using namespace std;
int a,car[6],ans;

int main()
{
    scanf("%d",&a);
    a%=10;
    for(int i=1;i<=5;i++){
        scanf("%d",&car[i]);
        if(car[i]==a) ans++;
    }
    printf("%d",ans);


    return 0;
}