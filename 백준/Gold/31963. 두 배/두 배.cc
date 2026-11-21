#include <bits/stdc++.h>

using namespace std;

int n;
int arr[250005];
int calc[250005];

long long ans;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=1; i<n; i++){
        calc[i] = max((int)ceil(log2( (double)arr[i-1] / (double)arr[i]) + (double)calc[i-1]), 0);
        ans += calc[i];
    }
    
    printf("%lld", ans);
    
    return 0;
}