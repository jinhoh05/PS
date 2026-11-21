#include <bits/stdc++.h>

using namespace std;

int n;
long long int ans;
long long int arr[10005];

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%lld", &arr[i]);

    sort(arr, arr + n);

    ans = arr[n - 1];

    if(n % 2 != 0){
        if(n == 1) ans = arr[0];
        else{
            for(int i=0;i<n;i++){
                ans = max(ans, arr[i] + arr[n - 2 - i]);
            }
        }
    }

    else{
        for(int i=0;i<n;i++){
            ans = max(ans, arr[i] + arr[n - 1 - i]);
        }
    }

    printf("%lld", ans);

    return 0;
}
