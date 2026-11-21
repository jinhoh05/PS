#include <bits/stdc++.h>

using namespace std;

int n, k, cnt, sum;
int arr1[100005], arr2[100005];

vector<int> v;

int big(int num)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(num == v[i])
        {
            v[i] = 0;
            return 1;
        }
    }

    return 0;
}

void calc()
{
    int c = 0;

    for(int i = n - 1; c < k; i--)
    {
        v.push_back(arr2[i]);
        c++;
    }

    for(int i = 0; i < n; i++)
    {
        if(big(arr1[i]) && cnt < k)
        {
            sum += arr1[i] - cnt;
            cnt++;
        }
    }
}

void input()
{
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);

        arr2[i] = arr1[i];
    }
}

int main()
{
    input();

    sort(arr2, arr2 + n);

    calc();

    printf("%d", sum);

    return 0;
}
