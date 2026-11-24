#include <bits/stdc++.h>

using namespace std;
int r,c,q,a;
char forest[55][55];
int used[55][55],use[55][55];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};

struct data{
    int x,y,lev;
};
queue <data>que,knight;

void push(int x,int y,int lev){
    if(x < 1 || x > r || y < 1 || y > c) return;
    if(used[x][y]!=0)return;
    if(x == q && y == a) return;
    used[x][y]=lev;
    que.push({x,y,lev});
}

int bfs(){
    data t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            push(t.x+dx[i],t.y+dy[i],t.lev+1);
        }
    }
    return 0;
}

int pushing(int x,int y,int lev){
    if(x < 1 || x > r || y < 1 || y > c) return 0;
    if(use[x][y]!=0)return 0;
    if(x == q && y == a){
        use[x][y]=lev;
        return 1;
    }
    if(used[x][y] > 0 && used[x][y] <= lev) return 0;
    use[x][y]=lev;
    knight.push({x,y,lev});
}

int tbfs(){
    data t;
    while(!knight.empty()){
        t=knight.front();
        knight.pop();
        for(int i=0;i<4;i++){
            if(pushing(t.x+dx[i],t.y+dy[i],t.lev+1)==1){
                printf("%d",use[q][a]);
                return 0;
            }
        }
    }
    printf("impossible");
    return 0;
}

int main()
{
    scanf("%d %d",&r,&c);

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&forest[i][j]);
            if(forest[i][j] == '*'){
                used[i][j]=-1;
                que.push({i,j,0});
            }
            else if(forest[i][j] == 'S'){
                use[i][j]=-1;
                knight.push({i,j,0});
            }
            else if(forest[i][j] == 'X'){
                used[i][j]=1;
                use[i][j]=1;
            }
            else if(forest[i][j] == 'D'){
                q=i;
                a=j;
            }
        }
    }

    bfs();

    /*for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("%2d ",used[i][j]);
        }
        printf("\n");
    }*/

    tbfs();
    /*printf("\n");
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            printf("%2d ",use[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}