#include <bits/stdc++.h>

using namespace std;

int n;
int r, c;
int board[1505][1505];
int vt[1505][1505];

struct grass{

    int x, y, cost;

    bool operator<(const grass& t)const{
        return cost > t.cost;
    }

}gh[2250010];

struct Data{

    struct flower{

        int f_cnt, step, pos;

    }f[5];

    int cnt;

    void update(int f_cnt, int step, int pos){
        f[cnt] = { f_cnt, step,pos };
        for(int i=cnt; i>0; i--){
            if(f[i].step > f[i-1].step) swap(f[i], f[i-1]);
        }
        if(cnt<4) cnt++;
    }

    int query(int f_cnt, int pos){
        int mx = 0;
        for(int i=0; i<cnt; i++){
            if(abs(f[i].pos - pos) < 2) continue;
            if(f[i].f_cnt <= f_cnt) continue;
            if(mx < f[i].step) mx = f[i].step;
        }
        return mx;
    }

};

Data R[1505], C[1505];

void output(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", vt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    scanf("%d %d", &r, &c);

    int cnt=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &board[i][j]);
            gh[++cnt] = { i,j,board[i][j] };
        }
    }

    R[r].update(board[r][c], 1, c);
    C[c].update(board[r][c], 1, r);

    sort(gh + 1, gh + cnt + 1);

    for(int i=1; i<=n*n; i++){
        int nx=gh[i].x, ny=gh[i].y, cnt=0;
        int f_cnt = board[nx][ny];

        //output();

        if(nx-1 >= 1) cnt = max(cnt, R[nx-1].query(f_cnt, ny));
        if(nx+1 <= n) cnt = max(cnt, R[nx+1].query(f_cnt, ny));
        if(ny-1 >= 1) cnt = max(cnt, C[ny-1].query(f_cnt, nx));
        if(ny-1 <= n) cnt = max(cnt, C[ny+1].query(f_cnt, nx));

        R[nx].update(f_cnt, cnt+1, ny);
        C[ny].update(f_cnt, cnt+1, nx);
        vt[nx][ny] = cnt+1;

        if(nx == r && ny == c) break;
    }

    printf("%d", vt[r][c]);

    return 0;
}
