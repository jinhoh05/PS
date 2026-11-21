#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, cnt=1, nx, ny;
int r, c;
int anc[105][105];

char board[105][105];

vector<int> v;

void check(){
    int x=0, y=0;
    for(int i=r; i>=1; i--){
        for(int j=c; j>=1; j--){
            if(board[i][j] == 'x'){
                x = i;
                y = j;
                break;
            }
        }
        if(x) break;
    }

    if(x == 0){
        printf("%d %d %d", nx, ny, cnt);
        return;
    }

    cnt=1;
    while(1){
        if(board[x-cnt][y] == 'x' || board[x][y-cnt] == 'x') cnt++;
        else break;
    }

    if(ny > y){
        for(int i=1; i<=c; i++){
            if(board[x][i] == 'x'){
                y = i + cnt - 1;
                break;
            }
        }
    }

    printf("%d %d %d", x-cnt+1, y-cnt+1, cnt);
}

int main(){
    scanf("%d %d", &r, &c);

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            scanf(" %c", &board[i][j]);
            if(board[i][j] == 'x'){
                if(nx == 0) nx = i, ny = j;
            }
        }
    }

    while(1){
        if(board[nx+cnt][ny] == 'x' && board[nx][ny+cnt] == 'x') cnt++;
        else break;
    }
    printf("%d %d %d\n", nx, ny, cnt);

    for(int i=nx; i<nx+cnt; i++){
        for(int j=ny; j<ny+cnt; j++){
            board[i][j] = '.';
        }
    }

    check();

    return 0;
}
