#include <bits/stdc++.h>

using namespace std;
int x,y;
int sx,sy;
int t;
int fx,fy;

int main()
{
    scanf("%d %d %d %d %d",&x,&y,&sx,&sy,&t);

    fx = (sx+t) % (x*2);
    if(fx > x) fx=x*2-fx;

    fy = (sy+t) % (y*2);
    if(fy > y) fy=y*2-fy;

    printf("%d %d",fx,fy);
    return 0;
}