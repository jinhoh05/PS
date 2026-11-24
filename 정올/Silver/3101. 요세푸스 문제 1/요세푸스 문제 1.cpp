#include <bits/stdc++.h>

using namespace std;
int n, k, cnt, go;
int arr[10005];

void yose(int i, int lev){
    if(lev == k){
        printf("%d ",arr[i]);
        arr[i] = arr[arr[i]];
        go=i;
        return;
    }

    yose(arr[i], lev + 1);
}

int main()
{
    scanf("%d %d",&n, &k);
    for(int i=1;i<=n;i++) arr[i] = i + 1;
    arr[n] = 1, go = n;

    for(int i=1;i<=n;i++){
        yose(go, 1);
    }

    return 0;
}