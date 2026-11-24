#include <bits/stdc++.h>

using namespace std;
int p;
int adj[130][130];
int main()
{
    for(int i=65;i<=122;i++){
        for(int j=65;j<=122;j++){
            adj[i][j]=1e9;
        }
    }
    
    scanf("%d",&p);
    for(int i=1;i<=p;i++){
        char a,b;
        int d;
        scanf(" %c %c %d",&a,&b,&d);
        adj[a][b]=min(adj[a][b],d);
        adj[b][a]=min(adj[b][a],d);
        
    }

    for(int k=65;k<=122;k++){
        for(int i=65;i<=122;i++){
            for(int j=65;j<=122;j++){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    int ans,d=1e9;
    for(int i=65;i<=89;i++){
        if(adj[i][90] < d){
            ans=i;
            d=adj[i][90];
        }
    }

    printf("%c %d",ans,d);

    return 0;
}