#include <bits/stdc++.h>

using namespace std;

int n, k, add, ans;
int a[3005], b[3005];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    k = a[n-1];
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
        b[i] = b[i] - k - (k - a[i]);
        add = max(add, b[i]);
    }
    
    printf("%d", 2*k + add);
    
    return 0;
}