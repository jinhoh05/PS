#include <bits/stdc++.h>

using namespace std;
int n,m,ice[305][305];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool vt[305][305];

void melt(){
    int cop[305][305];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cop[i][j]=ice[i][j];
        }
    }

    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
             if(cop[i][j]){
                 int cnt=0;
                 for(int k=0;k<4;k++){
                      int x = i + dx[k];
                      int y = j + dy[k];
                      if (cop[x][y] == 0) cnt++;
                 }
                 ice[i][j] = max(cop[i][j]-cnt, 0);
             }
        }
    }
}

void dfs(int x,int y){
    vt[x][y] = true;

    for(int i=0;i<4;i++){
        int X = x+dx[i];
        int Y = y+dy[i];

        if(1 <= X && X < n-1 && 1 <= Y && Y < m-1){
            if(ice[X][Y] && !vt[X][Y]) dfs(X,Y);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&ice[i][j]);
        }
    }

    int year = 0;

    while(1){
        memset(vt, false, sizeof(vt));
        bool result=false;
        int cnt=0;

        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(ice[i][j] && vt[i][j] == false){
                    cnt++;
                    if(cnt == 2){
                        result = true;
                        break;
                    }
                    dfs(i,j);
                }
            }
        }

        if(result) break;

        if(cnt == 0){
            year=0;
            break;
        }

        melt();
        year++;

    }

    printf("%d",year);

    return 0;
}