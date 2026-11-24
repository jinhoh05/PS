#include <bits/stdc++.h>

using namespace std;
int cube[10][10],op[10];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void opposite(int path[7], int direction, int cnt, int x, int y, int idx) {
    int target;
    for(int i=0;i<4;i++){
        target = cube[x+dx[i]][y+dy[i]];
        if(x+dx[i] > 0 && y+dy[i] > 0 && x+dx[i] < 7 && y+dy[i] < 7 &&  target != 0 && path[target] == 0){
            path[target] = 1;

            if(direction == -1) opposite(path, i, 1, x+dx[i], y+dy[i], idx);

            else if(direction == i && cnt == 1 && (op[idx] == 0 || op[idx] == target) && (op[target] == 0 || op[target] == idx)){
                op[idx] = target;
                op[target] = idx;
                opposite(path, direction, cnt+1, x+dx[i], y+dy[i], idx);
            }

            else opposite(path, direction, cnt, x+dx[i], y+dy[i], idx);
        }

    }
}

int main()
{
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            scanf("%d",&cube[i][j]);
        }
    }

    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(cube[i][j] != 0) {
                int path[7]={0,};
                path[cube[i][j]] = 1;
                opposite(path, -1, 0, i, j, cube[i][j]);
            }
        }
    }

    int flag=0;
    for(int i=1;i<=6;i++){
        if(op[i] == 0) flag = 1;
    }

    if(flag) printf("0");
    else printf("%d",op[1]);

    return 0;
}