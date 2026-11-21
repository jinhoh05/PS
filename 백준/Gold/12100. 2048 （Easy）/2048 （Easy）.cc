#include <bits/stdc++.h>
using namespace std;

int n, ans;
int board[25][25];

void bruit_force(int x){
    queue<int> q;

    if(x == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]) q.push(board[i][j]);
                board[i][j] = 0;
            }

            int idx = 0;

            while(!q.empty()){
                int t = q.front();
                q.pop();


                if(board[i][idx] == 0) board[i][idx] = t;
                else if(board[i][idx] == t){
                    board[i][idx] *= 2;
                    idx++;
                }
                else{
                    idx++;
                    board[i][idx] = t;
                }
            }
        }
    }

    if(x == 1){
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(board[i][j]) q.push(board[i][j]);
                board[i][j] = 0;
            }

            int idx = n - 1;

            while(!q.empty()){
                int t = q.front();
                q.pop();

                if(board[i][idx] == 0) board[i][idx] = t;
                else if(board[i][idx] == t){
                    board[i][idx] *= 2;
                    idx--;
                }
                else{
                    idx--;
                    board[i][idx] = t;
                }
            }
        }
    }

    if(x == 2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[j][i]) q.push(board[j][i]);
                board[j][i] = 0;
            }

            int idx = 0;

            while(!q.empty()){
                int t = q.front();
                q.pop();

                if(board[idx][i] == 0) board[idx][i] = t;
                else if(board[idx][i] == t){
                    board[idx][i] *= 2;
                    idx++;
                }
                else{
                    idx++;
                    board[idx][i] = t;
                }
            }
        }
    }

    if(x == 3){
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(board[j][i]) q.push(board[j][i]);
                board[j][i] = 0;
            }

            int idx = n - 1;

            while(!q.empty()){
                int t = q.front();
                q.pop();

                if(board[idx][i] == 0) board[idx][i] = t;
                else if(board[idx][i] == t){
                    board[idx][i] *= 2;
                    idx--;
                }
                else{
                    idx--;
                    board[idx][i] = t;
                }
            }
        }
    }
}

void dfs(int cnt){
    if(cnt == 5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }

    int c_board[25][25];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c_board[i][j] = board[i][j];
        }
    }

    for(int k=0;k<4;k++){
        bruit_force(k);
        dfs(cnt + 1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = c_board[i][j];
            }
        }
    }
}

void input(){
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&board[i][j]);
        }
    }
}

int main(){

    input();

    dfs(0);

    printf("%d",ans);

    return 0;
}
