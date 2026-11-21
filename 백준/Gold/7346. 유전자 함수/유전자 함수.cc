#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;
const int score[5][5] =
   {{5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, -INF}};

int len1, len2;
int seq[100];
int DP[105][105];

string s1, s2;

void init()
{
    s1 = '0' + s1;
    s2 = '0' + s2;

    if(len1 < len2)
    {
        swap(len1, len2);
        swap(s1, s2);
    }

    seq['A'] = 0;
    seq['C'] = 1;
    seq['G'] = 2;
    seq['T'] = 3;

    for(int i = 1; i <= len1; i++) DP[i][0] = DP[i - 1][0] + score[seq[s1[i]]][4];
    for(int i = 1; i <= len2; i++) DP[0][i] = DP[0][i - 1] + score[4][seq[s2[i]]];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> len1 >> s1;
        cin >> len2 >> s2;

        init();

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                DP[i][j] = DP[i - 1][j - 1] + score[seq[s1[i]]][seq[s2[j]]];
                DP[i][j] = max(DP[i][j], DP[i - 1][j] + score[seq[s1[i]]][4]);
                DP[i][j] = max(DP[i][j], DP[i][j - 1] + score[4][seq[s2[j]]]);
            }
        }

        printf("%d\n", DP[len1][len2]);

        memset(DP, 0, sizeof(DP));
    }

    return 0;
}
