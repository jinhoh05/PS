#include <bits/stdc++.h>

using namespace std;

int n;
int arr[250005];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }

    int cnt=0;
    for(int i=1; i<=n; i++){
        if(arr[i]+cnt != i) cnt++;
    }

    printf("%d", cnt);

    return 0;
}
