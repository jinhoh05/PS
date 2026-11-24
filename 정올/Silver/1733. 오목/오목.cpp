#include <bits/stdc++.h>

using namespace std;
int a[22][22]={0};

int ans(int x,int y,int d){
    int dx[4]={1,0,1,1};
    int dy[4]={1,1,0,-1};

    if(x+dx[d] < 1 || x+dx[d] > 20) return 0;

    if(y+dy[d] < 1 || y+dy[d] > 20) return 0;

    if(a[x][y] == 0) return 0;

    if(a[x-dx[d]][y-dy[d]] == a[x][y]) return 0;

    if(a[x+dx[d]*5][y+dy[d]*5] == a[x][y]) return 0;

    for(int i=0;i<4;i++){
        if(a[x][y] != a[x+dx[d]][y+dy[d]]){
            return 0;
        }
        x+=dx[d];
        y+=dy[d];
    }

    return 1;
}

int omok(){

    for(int i=1;i<20;i++){
        for(int j=1;j<20;j++){
            for(int d=0;d<4;d++){
                if(ans(i,j,d)){
                    if(d==3){
                        printf("%d\n%d %d",a[i][j],i+4,j-4);
                        return 0;
                    }
                    else{
                        printf("%d\n%d %d",a[i][j],i,j);
                    }
                    return 0;
                }
            }
        }
    }
    printf("0");
}

int main()
{
    for(int i=1;i<20;i++){
        for(int j=1;j<20;j++){
            scanf("%d",&a[i][j]);
        }
    }


    omok();
    
    return 0;
}