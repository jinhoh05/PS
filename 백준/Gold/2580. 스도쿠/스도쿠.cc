#include <bits/stdc++.h>

using namespace std;
int cnt, k;
int a[85][3];
int sdq[10][10], row[10][10], col[10][10], g[3][3][10];

void output(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",sdq[i][j]);
        }
        printf("\n");
    }
}

int check(int x,int y,int z){
    if(row[x][z] == 1 || col[z][y] == 1) return 0;

    if(g[x / 3][y / 3][z] == 1) return 0;

    return 1;
}

int dfs(int lev){
    if(lev > cnt){
        output();
        return 1;
    }

    int x = a[lev][1], y = a[lev][2];

    for(int j=1;j<=9;j++){

        if(check(x, y, j) == 1){
            row[x][j] = 1;
            col[j][y] = 1;
            g[x/3][y/3][j] = 1;
            sdq[x][y] = j;

            if(dfs(lev + 1) == 1) return 1;

            sdq[x][y] = 0;
            row[x][j] = 0;
            col[j][y] = 0;
            g[x / 3][y / 3][j]=0;
        }
    }

    return 0;
}

void input(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            scanf("%d",&k);

            sdq[i][j] = k;

            if(k == 0){
                cnt++;
                a[cnt][1]=i;
                a[cnt][2]=j;
            }

            else{
                row[i][k]=1;
                col[k][j]=1;
                g[i/3][j/3][k]=1;
            }
        }
    }
}

int main()
{
    input();

    dfs(1);

    return 0;
}
