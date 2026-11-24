#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans = 100005, res;
int arr[100005];
int mx1, mx2, vt;    
int lr1, lr2;

string s;
vector<int> v;

void setting()
{
    for (int k = 0, i = 1; i <= n; i++)
    {
        if (arr[i])
        {
            if (k){
                ans = min(ans, i - k);
                if (mx1 < i - k)
                {
                    mx1 = i - k;
                    vt = i;
                }
            }
            k = i;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i]){
            lr1 = i - 1;
            break;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        if (arr[i]){
            lr2 = n - i;
            break;
        }
    }

    if (lr1 < lr2) swap(lr1, lr2);

    for (int k = 0, i = 1; i <= n; i++)
    {
        if (arr[i])
        {
            if (k && vt != i) mx2 = max(mx2, i - k);
            k = i;
        }
    }
}

void house()
{
    res = max(res, lr1 / 2);
    res = max(res, lr2);
    res = max(res, mx1 / 3);
    res = max(res, mx2 / 2);
    res = max(res, min(lr1, mx1 / 2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        arr[i + 1] = s[i] - '0';
        if (arr[i + 1]) cnt++;
    }

    if (!cnt) {
        cout << n - 1;
        return 0;
    }

    setting();

    house();

    cout << min(ans, res);

    return 0;
}