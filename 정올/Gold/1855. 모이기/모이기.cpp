#include <bits/stdc++.h>

using namespace std;
int n,p,c,dis=1e9;
int road[805][805];
int state[505];

void least(){
    for(int i=1;i<=p;i++){
        int hap=0;
        for(int j=1;j<=n;j++){
            hap+=road[state[j]][i];
        }
        dis=min(dis,hap);
    }
}

void floyd(){
    for(int k=1;k<=p;k++){
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                road[i][j]=min(road[i][j],road[i][k]+road[k][j]);
            }
        }
    }
}

void overlap(int x,int y,int t){
    if(road[x][y]) t=min(road[x][y],t);
    road[x][y]=t;
    road[y][x]=t;
}

int main()
{
    scanf("%d %d %d",&n,&p,&c);

    for(int i=1;i<=p;i++){
        for(int j=1;j<=p;j++){
            road[i][j]=1e9;
            if(i==j) road[i][j]=0;
        }
    }

    for(int i=1;i<=c;i++){
        int x,y,t;
        scanf("%d %d %d",&x,&y,&t);
        overlap(x,y,t);
    }

    for(int i=1;i<=n;i++){
        scanf("%d",&state[i]);
    }

    floyd();
    least();

    printf("%d",dis);

    return 0;
}