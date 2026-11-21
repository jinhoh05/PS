#include <bits/stdc++.h>
 
using namespace std;
int f,adj[505][505],black[205][205];
 
void reset(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=1e9;
        }
    }
 
}
 
void floyd(int n){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}
 
int check(int n){
    for(int i=1;i<=n;i++){
        if(adj[i][i] < 0) return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&f);
    for(int i=1;i<=f;i++){
        int n,m,b,chk;
        scanf("%d %d %d",&n,&m,&b);
        reset(n);
 
        for(int j=1;j<=m;j++){
            int s,e,t;
            scanf("%d %d %d",&s,&e,&t);
            adj[s][e]=min(adj[s][e],t);
            adj[e][s]=min(adj[e][s],t);
        }
 
        for(int j=1;j<=b;j++){
            int s,e,t;
            scanf("%d %d %d",&s,&e,&t);
            adj[s][e]=min(adj[s][e],-t);
        }
        floyd(n);
         
        chk=check(n);
        if(chk==1) printf("YES\n");
        else printf("NO\n");
    }
 
    return 0;
}