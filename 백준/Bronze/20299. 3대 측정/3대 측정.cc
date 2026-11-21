#include <bits/stdc++.h>

using namespace std;

int n, k, l, cnt;
int arr[500005][5];

int main()
{
    scanf("%d %d %d", &n, &k, &l);
    for(int i=1;i<=n;i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if(a < l || b < l || c < l) continue;
        if(a + b + c < k) continue;

        cnt++;
        arr[cnt][1] = a;
        arr[cnt][2] = b;
        arr[cnt][3] = c;
    }

    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d %d %d ", arr[i][1], arr[i][2], arr[i][3]);
    }

    return 0;
}
