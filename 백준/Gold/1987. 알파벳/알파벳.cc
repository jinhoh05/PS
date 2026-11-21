#include <bits/stdc++.h>

using namespace std;

int r, c, x, y, ans;
char board[20][20];
int horse[26];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

void dfs(int x,int y,int lev){
    ans=max(ans, lev);

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

        int k = board[nx][ny] - 65;
        if(horse[k]) continue;

        horse[k]++;
        dfs(nx, ny, lev+1);
        horse[k]--;
    }
}

int main(){

    scanf("%d %d", &r, &c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %c", &board[i][j]);
        }
    }

    horse[board[x][y] - 65]++;
    dfs(0,0,1);

    printf("%d",ans);

    return 0;
}
