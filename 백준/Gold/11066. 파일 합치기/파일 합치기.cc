#include <bits/stdc++.h>

using namespace std;

int t, k;
int file[505], cost[505];
int DP[505][505];

void dynamic(int x, int y){
    DP[x][y] = 1e9;

    for(int i=x;i<y;i++){
        int MIN_cost = DP[x][i] + DP[i + 1][y];
        int MIN_file = file[y] - file[x - 1];

        DP[x][y] = min(DP[x][y], MIN_cost + MIN_file);
    }
}

void input(){
    scanf("%d", &k);

    for(int i=1;i<=k;i++){
        scanf("%d", &cost[i]);
        file[i] = file[i - 1] + cost[i];
    }
}

int main()
{
    scanf("%d", &t);

    while(t--){
        input();

        for(int j=1;j<k;j++) {
            for(int x=1;x+j<=k;x++){
                dynamic(x, x + j);
            }
        }

        printf("%d\n", DP[1][k]);
    }

    return 0;
}
