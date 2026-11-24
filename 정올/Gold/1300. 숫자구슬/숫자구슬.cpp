#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[305];

bool possible(int mid)
{
    int sum = 0, cnt = 1;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum > mid)
        {
            sum = arr[i];
            cnt++;
        }
    }

    return cnt <= m;
}

void output(int mid)
{
    printf("%d\n", mid);

    int sum = 0, cnt = 0;

    for(int i = 0; i < n; i++)
    {
        sum += arr[i];

        if(sum > mid)
        {
            sum = arr[i];
            m--;
            printf("%d ",cnt);
            cnt = 0;
        }

        cnt++;

        if(n - i == m) break;
    }

    while(m--)
    {
        printf("%d ", cnt);
        cnt = 1;
    }
}


int main()
{
    int l = 0, r = 0, mid;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);

        l = max(l, arr[i]);
        r += arr[i];
    }

    while (l <= r)
    {
        mid = (l + r) / 2;
        if(possible(mid)) r = mid - 1;
        else l = mid + 1;
    }

    output(l);

    return 0;
}