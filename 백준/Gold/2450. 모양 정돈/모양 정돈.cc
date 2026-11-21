#include <bits/stdc++.h>

using namespace std;

int ans = 1e9;
int cnt[5], p[3] = {1, 2, 3};

vector<int> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
        cnt[a]++;
    }

    do{
        int arr[5][5] = {0};
        int s = 0;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < cnt[p[i]]; j++)
            {
                arr[p[i]][v[s + j]]++;
            }

            s += cnt[p[i]];
        }

        ans = min(ans, arr[1][2] + arr[1][3] + max(arr[2][3], arr[3][2]));
    } while(next_permutation(p, p + 3));

    cout << ans;

    return 0;
}
