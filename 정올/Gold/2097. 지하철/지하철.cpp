#include <bits/stdc++.h>

using namespace std;
int n,m;
int adjMat[105][105];
int dist[105];
int path[105], visit[105];

int dijkstra(){
    for(int i=1; i<=n; i++){
        //if(visit[m]) return 0;
        int minNode, minVal =21e8;
        for (int j=1; j<=n; j++){
            if(visit[j]==0 && minVal>dist[j]){
                minNode = j, minVal = dist[j];
            }
        }
        visit[minNode] = 1;
        for(int j=1; j<=n; j++){
            if(dist[j] > minVal + adjMat[minNode][j]){
                dist[j] = minVal + adjMat[minNode][j];
                path[j] = minNode;
            }
        }
    }
    return 0;
}

void move(int s){
    if(path[s]==0) return;
    move(path[s]);
    printf("%d ",s);
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&adjMat[i][j]);
        }
    }

    for(int i=1; i<=n; i++) dist[i] = 21e8;
    dist[1] = 0;
    dijkstra();

    printf("%d\n1 ",dist[m]);
    move(m);

    return 0;
}