#include <bits/stdc++.h>

using namespace std;

int n, cnt;

string sign, old;

void check()
{
    for(int i = 0; i < old.size(); i++)
    {
        for(int j = 1; i + (sign.size() - 1) * j < old.size(); j++)
        {
            bool flag = true;

            for(int k = 0; k < sign.size(); k++)
            {
                if(old[i + k * j] != sign[k])
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                cnt++;
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> sign;

    for(int i = 0; i < n; i++)
    {
        cin >> old;

        check();
    }

    cout << cnt;

    return 0;
}
