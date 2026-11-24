#include <bits/stdc++.h>

using namespace std;

int N, ans;

vector<int> v;

bool check(int val)
{
    auto p = find(v.begin(), v.end(), val);

    if(p != v.end()) return true;
    return false;
}

void multi(int a, int b, int c, int d, int e)
{
    bool flag = true;

    int num = (v[a] * 100) + (v[b] * 10) + v[c], sum = 0;

    int val = num * v[e];

    if(val > 999) flag = false;

    sum += val;

    while(val > 0)
    {
        if(!check(val % 10)) flag = false;
        val /= 10;
    }

    val = num * v[d];
    sum += val * 10;

    if(val > 999) flag = false;
    if(sum > 9999) flag = false;

    while(val > 0)
    {
        if(!check(val % 10)) flag = false;
        val /= 10;
    }

    while(sum > 0)
    {
        if(!check(sum % 10)) flag = false;
        sum /= 10;
    }

    if(flag)
    {
        ans++;
        //printf("%d %d %d %d %d\n", a, b, c, d, e);
    }

    if(e < N - 1) multi(a, b, c, d, e + 1);
    else if(d < N - 1) multi(a, b, c, d + 1, 0);
    else if(c < N - 1) multi(a, b, c + 1, 0, 0);
    else if(b < N - 1) multi(a, b + 1, 0, 0, 0);
    else if(a < N - 1) multi(a + 1, 0, 0, 0, 0);
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    multi(0, 0, 0, 0, 0);

    printf("%d", ans);

    return 0;
}
