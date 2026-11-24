#include <bits/stdc++.h>

using namespace std;

int n, val, s;
int arr[105];

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);

        s = (s + val) % n;
        val = arr[s];

        while(val > 0){
            s = (s + 1) % n;
            val = arr[s];
        }

        arr[s] = x;
        val = x;
    }

    printf("%d\n", n);

    for(int i = 0; i < n; i++) printf("%d ", arr[i]);

    return 0;
}