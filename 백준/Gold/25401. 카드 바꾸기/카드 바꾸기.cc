#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, ans;
int arr[505];

int asc(int seq[], int q){
    if(q == 2) reverse(seq+1, seq+n+1);

    int a=1e9;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int d = (seq[j] - seq[i]) / (j - i), ans=0;
            if((seq[j] - seq[i]) % (j - i) != 0) continue;

            for(int k=i-1; k>=1; k--){
                if(seq[i] - d*(i-k) != seq[k]) ans++;
            }
            for(int k=i+1; k<=n; k++){
                if(seq[i] + d*(k-i) != seq[k]) ans++;
            }

            a = min(a, ans);
        }
    }

    return a;
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    arr[n+1] = arr[n]*2;

    ans = min(asc(arr, 1), asc(arr, 2));

    printf("%d", ans);

    return 0;
}
