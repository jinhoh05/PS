#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
int L[45];
int DP[2][576][576];

ll S;

double s;
double ans = -1;

void calc(int i, int j)
{
    vector<int> v;
    v.push_back(i);
    v.push_back(j);
    v.push_back(2 * s - (i + j));
    sort(v.begin(), v.end());

    if(v[0] + v[1] <= v[2] || v[0] == 0) return;

    double sum = s * (s - i) * (s - j) * (-s + i + j);
    sum = sqrt(sum) * 100;
    ans = max(ans, sum);
}

int main()
{
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &L[i]);
        S += L[i];
    }

    sort(L + 1, L + N + 1);

    DP[0][0][0] = 1;

    for(int k = 1; k <= N; k++)
    {
        for(int i = 0; i <= min((ll)575, S); i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(DP[1 - k % 2][i][j]) DP[k % 2][i][j] = 1;
                else if(i >= L[k] && DP[1 - k % 2][i - L[k]][j]) DP[k % 2][i][j] = 1;
                else if(i >= L[k] && DP[1 - k % 2][j][i - L[k]]) DP[k % 2][i][j] = 1;
                else if(j >= L[k] && DP[1 - k % 2][i][j - L[k]]) DP[k % 2][i][j] = 1;
            }
        }
    }

    s = (double)S / 2;

    for(int i = 0; i <= min((ll)575, S); i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(DP[N % 2][i][j]) calc(i, j);
        }
    }

    printf("%.f", floor(ans));

    return 0;
}
