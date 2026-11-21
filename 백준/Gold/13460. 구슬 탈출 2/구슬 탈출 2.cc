#include<bits/stdc++.h>

using namespace std;

int n, m;
int vt[15][15][15][15];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char board[15][15];

struct st{
    int bx, by, rx, ry;
};
st ball;

queue<st> que;

int bfs() {
    vt[ball.bx][ball.by][ball.rx][ball.ry] = 1;
    int ans = 0, escape = 0;

    que.push(ball);

    while(que.size()){
        int cnt = que.size();

        while(cnt--){
            st t = que.front();
            que.pop();

            if(board[t.rx][t.ry] == 'O'){
                escape = 1;
                break;
            }

            for(int d=0;d<4;d++){
                int out[2] = {0, 0};
                int q[2] = {}, p[2][2] = {{t.bx, t.by }, {t.rx, t.ry}};

                for(int i=0;i<2;i++) {
                    while(board[p[i][0] + dx[d]][p[i][1] + dy[d]] != '#'){
                        q[i]++;
                        p[i][0] = p[i][0] + dx[d];
                        p[i][1] = p[i][1] + dy[d];
                        if(board[p[i][0]][p[i][1]] == 'O') break;
                    }
                    out[i] = board[p[i][0]][p[i][1]] == 'O';
                }

                if(out[0]) continue;

                if(p[0][0] == p[1][0] && p[0][1] == p[1][1]){
                    if(q[0] > q[1]){
                        p[0][0] -= dx[d];
                        p[0][1] -= dy[d];
                    }

                    else{
                        p[1][0] -= dx[d];
                        p[1][1] -= dy[d];
                    }
                }

                if(vt[p[0][0]][p[0][1]][p[1][0]][p[1][1]]) continue;
                vt[p[0][0]][p[0][1]][p[1][0]][p[1][1]] = 1;

                st next = {p[0][0], p[0][1], p[1][0], p[1][1]};
                que.push(next);
            }
        }

        if(escape) break;
        ans++;

        if(ans > 10) break;
    }

    return escape ? ans : -1;
}

void check(int i, int j){
    if(board[i][j] == 'R') {
        ball.rx = i;
        ball.ry = j;
        board[i][j] = '.';
    }

    else if(board[i][j] == 'B') {
        ball.bx = i;
        ball.by = j;
        board[i][j] = '.';
    }
}

void input(){
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c", &board[i][j]);
            check(i, j);
        }
    }
}

int main() {

    input();

    printf("%d", bfs());

    return 0;
}
