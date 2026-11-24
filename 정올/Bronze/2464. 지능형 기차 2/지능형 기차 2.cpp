#include <bits/stdc++.h>
using namespace std;

int x,y,ans,people;
int arr[300];

int main() {
    //freopen("input.txt","r",stdin);

    for(int i=1;i<=10;i++){
        scanf("%d %d",&x,&y);
        people-=x;
        people+=y;
        ans=max(ans,people);
    }
    printf("%d",ans);
}