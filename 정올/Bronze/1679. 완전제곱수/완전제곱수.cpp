#include <bits/stdc++.h>

using namespace std;

int N, M;
int hap, small;
int vt[10005];

int main()
{
    for(int i = 1; i <= 100; i++) vt[i * i] = 1;

    scanf("%d %d", &N, &M);

    for(int i = M; i >= N; i--)
    {
        if(vt[i])
        {
            hap += i;
            small = i;
        }
    }

    printf("%d\n%d", hap, small);

    return 0;
}