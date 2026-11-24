#include <bits/stdc++.h>
using namespace std;
int n,x,y,tile[515][515];

void t(int sx, int sy, int ex, int ey, int hx, int hy, int hc){
    int mx=(sx+ex)/2,my=(sy+ey)/2;

    if(sx==ex){
        tile[sx][sy]=hc;
        return;
    }

    if(hx>=sx && hx<=mx && hy>=sy && hy<=my){
        tile[mx+1][my]=1;
        tile[mx][my+1]=1;
        tile[mx+1][my+1]=1;

        t(sx,sy,mx,my,hx,hy,hc);
        t(mx+1,sy,ex,my,mx+1,my,1);
        t(sx,my+1,mx,ey,mx,my+1,1);
        t(mx+1,my+1,ex,ey,mx+1,my+1,1);
    }

    else if(hx>=mx+1 && hx<=ex && hy>=sy && hy<=my){
        tile[mx][my]=2;
        tile[mx+1][my]=2;
        tile[mx+1][my+1]=2;

        t(sx,sy,mx,my,mx,my,3);
        t(mx+1,sy,ex,my,hx,hy,hc);
        t(sx,my+1,mx,ey,mx,my+1,3);
        t(mx+1,my+1,ex,ey,mx+1,my+1,3);
    }
    else if(hx>=sx && hx<=mx && hy>=my+1 && hy<=ey){
        tile[mx][my]=3;
        tile[mx][my+1]=3;
        tile[mx+1][my+1]=3;

        t(sx,sy,mx,my,mx,my,2);
        t(mx+1,sy,ex,my,mx+1,my,2);
        t(sx,my+1,mx,ey,hx,hy,hc);
        t(mx+1,my+1,ex,ey,mx+1,my+1,2);
    }

    else if(hx>=mx+1&&hx<=ex&&hy>=my+1&&hy<=ey){
        tile[mx][my]=4;
        tile[mx+1][my]=4;
        tile[mx][my+1]=4;

        t(sx,sy,mx,my,mx,my,4);
        t(mx+1,sy,ex,my,mx+1,my,4);
        t(sx,my+1,mx,ey,mx,my+1,4);
        t(mx+1,my+1,ex,ey,hx,hy,hc);
    }

}
int main()
{
    scanf("%d %d %d",&n,&x,&y);

    t(1,1,n,n,x+1,y+1,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",tile[i][j]);
        }
        printf("\n");
    }
}