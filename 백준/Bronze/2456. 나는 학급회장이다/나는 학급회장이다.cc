#include <bits/stdc++.h>

using namespace std;

pair<int, int> s[5];

int main()
{
    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int a;
            cin >> a;
            s[j].first += a;
            s[j].second += a * a;
        }
    }

    int a = 0, b = 0;

    if(s[0] < s[1]) a = 1;

    else if(s[0] == s[1]) b = 1;

    if(s[a] < s[2]) a = 2, b = 0;

    else if(s[a] == s[2]) b = 1;

    cout << (b ? 0 : a + 1) << " " << s[a].first;

    return 0;
}
