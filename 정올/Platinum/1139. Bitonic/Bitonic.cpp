#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int MAX = 10000;

int n;

double dist[105][105];
double DP[105][105];

vector<pii> v;

void calc(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x = v[j].first - v[i].first;
            int y = v[j].second - v[i].second;

            dist[i][j] = sqrt((x * x) + (y * y));
        }
    }
}

double bitonic_cycle(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            DP[i][j] = 1e9;
        }
    }

    DP[1][0] = DP[0][1] = dist[0][1];

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(i == j) continue;

            int k = max(i, j) + 1;
            
            DP[k][j] = min(DP[k][j], DP[i][j] + dist[i][k]);
            DP[i][k] = min(DP[i][k], DP[i][j] + dist[j][k]);
        }
    }

    double ans = 1e9;

    for(int i = 0; i < n - 1; i++) ans = min(ans, DP[n - 1][i] + dist[i][n - 1]);

    return ans;
}

int main()
{
    scanf("%d", &n);

    v.resize(n);

    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        x += MAX, y += MAX;

        v[i] = make_pair(x, y);
    }

    sort(v.begin(), v.end());

    calc();

    printf("%.2f", bitonic_cycle());

    return 0;
}