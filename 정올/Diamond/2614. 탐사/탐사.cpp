#include <bits/stdc++.h>

using namespace std;
int k,n;
int probe[45][45];

int main()
{
    scanf("%d %d",&k,&n);

    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            probe[i][j]=1e9;
        }
    }

    probe[0][0]=0;
    for(int i=1;i<=k;i++){
        probe[i][i-1]=probe[i][i]=0;
        probe[i-1][i]=1;
    }

    for(int i=0;i<n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(probe[x-1][y] > z) probe[x-1][y]=z;
        probe[y][x-1]=-z;
    }

    for(int h=0;h<=k;h++){
        for(int i=0;i<=k;i++){
            for(int j=0;j<=k;j++){
                if(probe[i][h] + probe[h][j] < probe[i][j]) probe[i][j] = probe[i][h] + probe[h][j];
            }
        }
    }

    for(int i=0;i<=k;i++){
        if(probe[i][i] < 0){
            puts("NONE");
            return 0;
        }
    }

    for(int i=0;i<k;i++){
        putchar((probe[0][i+1] - probe[0][i]) ? '#' : '-');
    }

    return 0;
}