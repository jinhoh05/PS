#include <bits/stdc++.h>

using namespace std;

int n, w;
int ans_x, ans_y;
int DP[1005][1005];
int path[1005][1005];
int xrr[1005], yrr[1005];

void init()
{
	for(int i = 1; i <= w; i++){
        for(int j = 1; j <= w; j++){
            DP[i][j] = 1e9;
        }
    }

    DP[1][2] = 0;
}

int get_d(int a, int b)
{
    return abs(xrr[a] - xrr[b]) + abs(yrr[a] - yrr[b]);
}

void bitonic()
{
    for(int i = 1; i < w; i++){
        for(int j = 1; j < w; j++){
            if(DP[i][j] == 1e9) continue;

            int nxt = max(i, j) + 1;
            int d1 = get_d(nxt, i) + DP[i][j], d2 = get_d(j, nxt) + DP[i][j];

            if(DP[nxt][j] > d1){
                DP[nxt][j] = d1;
                path[nxt][j] = i;
            }

            if(DP[i][nxt] > d2){
                DP[i][nxt] = d2;
                path[i][nxt] = j;
            }
        }
    }
}

void trace(int r, int c)
{
    if(r == 1 && c == 2) return;

    if(r > c){
        trace(path[r][c], c);
        printf("1\n");
    }

    else{
        trace(r, path[r][c]);
        printf("2\n");
    }
}

void output(){
	int r = 1, c = 1;

	for(int i = 1; i <= w; i++){
        if(DP[r][c] > DP[i][w]) r = i, c = w;
        if(DP[r][c] > DP[w][i]) r = w, c = i;
    }

    printf("%d\n", DP[r][c]);

    trace(r, c);
}

void input(){
    scanf("%d %d", &n, &w);

    xrr[1] = yrr[1] = 1;
    xrr[2] = yrr[2] = n;

    w += 2;

    for(int i = 3; i <= w; i++){
        scanf("%d %d", &xrr[i], &yrr[i]);
    }
}

int main()
{
    input();

	init();

    bitonic();

	output();

    return 0;
}