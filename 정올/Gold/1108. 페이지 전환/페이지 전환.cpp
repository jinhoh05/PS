#include <bits/stdc++.h>

using namespace std;
int n,tmp,mx;
int dist[505][505];
double ans;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        dist[a][b]=1;
        tmp=(a > b ? a : b);
        mx=(tmp > mx ? tmp : mx);
    }

    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx;j++){
            if(!dist[i][j]) dist[i][j]=1000;
        }
    }

    for(int k=1;k<=mx;k++){
        for(int i=1;i<=mx;i++){
            for(int j=1;j<=mx;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j]= dist[i][k] + dist[k][j];
            }
        }
    }

    for(int i=1;i<=mx;i++){
        for(int j=1;j<=mx;j++){
            if(i!=j) ans+=dist[i][j];
        }
    }

    printf("%.3f", ans / (mx*(mx-1)));

    return 0;
}