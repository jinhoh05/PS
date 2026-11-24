#include <bits/stdc++.h>

using namespace std;
int n,m;
int data[505][505];
int x,y;
int cnt;

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;i++){
        scanf("%d %d",&x,&y);
        data[x][y]=1;
    }

    for(int k=1;k<=n;k++){
        int sum=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(data[i][k] == 1 && data[k][j] == 1){
                    data[i][j]=1;
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(data[i][j] == 1) sum++;
            if(data[j][i] == 1) sum++;
        }
        if(sum == n-1) cnt++;
    }

    printf("%d",cnt);

    return 0;
}