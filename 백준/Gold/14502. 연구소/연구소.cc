#include <bits/stdc++.h>

using namespace std;
int n, m, ans;
int lab[10][10], arr[10][10];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


void lab_copy(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           arr[i][j] = lab[i][j];
        }
    }
}

void virus(){
    int check[10][10];
    queue<pair<int, int>> q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            check[i][j] = arr[i][j];
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check[i][j] == 2) q.push({i, j});
        }
    }


    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;

            if(check[nx][ny] == 0){
                check[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }


    int vir = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(check[i][j] == 0) vir++;
        }
    }

    ans = max(ans, vir);
}

void wall(int lev){
    if(lev == 3){
        virus();
        return;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(arr[i][j] == 0){
                 arr[i][j] = 1;
                 wall(lev + 1);
                 arr[i][j] = 0;
             }
        }
    }
}

void laboratory(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(lab[i][j] == 0){
                 lab_copy();

                 arr[i][j] = 1;
                 wall(1);
                 arr[i][j] = 0;
             }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &lab[i][j]);
        }
    }

    laboratory();

    printf("%d", ans);

    return 0;
}
