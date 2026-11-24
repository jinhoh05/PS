#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int MAX = 1005;

int n, w, ans;
int ans_x, ans_y;
int DP[MAX][MAX];
int path[MAX][MAX];
int xrr[MAX], yrr[MAX];

pii vt[MAX][MAX];

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

            if(DP[nxt][j] > d1) DP[nxt][j] = d1;

            if(DP[i][nxt] > d2) DP[i][nxt] = d2;
        }
    }
}

queue<pii> q;

void push(int x, int y){
	if(x < 1 || x > w || y < 1 || y > w) return;

	if(x > y){
		if(DP[x + 1][y] != 1e9 && vt[x + 1][y].first == 0 && DP[x][y] + get_d(x + 1, x) == DP[x + 1][y]){
			q.push({x + 1, y});
			vt[x + 1][y] = make_pair(x, y);
		}

		if(DP[x][x + 1] != 1e9 && vt[x][x + 1].second == 0 && DP[x][y] + get_d(y, x + 1) == DP[x][x + 1]){
			q.push({x, x + 1});
			vt[x][x + 1] = make_pair(x, y);
		}
	}

	else{
		if(DP[y + 1][y] != 1e9 && vt[y + 1][y].second == 0 && DP[x][y] + get_d(y + 1, x) == DP[y + 1][y]){
			q.push({y + 1, y});
			vt[y + 1][y] = make_pair(x, y);
		}

		if(DP[x][y + 1] != 1e9 && vt[x][y + 1].second == 0 && DP[x][y] + get_d(y, y + 1) == DP[x][y + 1]){
			q.push({x, y + 1});
			vt[x][y + 1] = make_pair(x, y);
		}
	}
}

pii bfs(int x, int y){
	q.push({x, y});
	vt[1][2] = make_pair(-1, 0);

	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if((x == w || y == w) && DP[x][y] == ans) return make_pair(x, y);

		push(x, y);
	}
}

void trace(pii p){
	int x1 = p.first, y1 = p.second;
	int x2 = vt[x1][y1].first, y2 = vt[x1][y1].second;

	if(vt[x1][y1].first == -1) return;

	trace(vt[x1][y1]);

	if(x1 != x2) printf("1\n");
	else printf("2\n");
}

void output(){
    int r = 1, c = 1;

    for(int i = 1; i <= w; i++){
        if(DP[r][c] > DP[i][w]) r = i, c = w;
        if(DP[r][c] > DP[w][i]) r = w, c = i;
    }

    printf("%d\n", DP[r][c]);

    ans = DP[r][c];

	trace(bfs(1, 2));
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