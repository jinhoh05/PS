#include <bits/stdc++.h>

using namespace std;
using pii=pair<int, int>;

int tri[15][15],vt[15][15],vis[15][15],cnt,v_cnt,t;
pii v[15];

void ver(int x, int y){
    if(tri[x][y] == 1 && vis[x][y] == 0){
        if(tri[x][y-1] + tri[x][y+1] + tri[x+1][y] + tri[x-1][y] == 1) v[++v_cnt]=make_pair(x,y);
        vis[x][y]=1;
    }
    else return;

    ver(x, y-1);
    ver(x, y+1);
    ver(x+1, y);
}

pii triangle(){
    for(int i=1;i<=10;i++){
        if(cnt == i*i) return make_pair(1,i);
        if(cnt == i*(i+1)/2) return make_pair(2,i);
    }

    return make_pair(0,0);
}

void check(int x, int y){
    if(tri[x][y] == 1 && vt[x][y] == 0){
        cnt++;
        vt[x][y] = 1;
    }
    else return;

    check(x, y-1);
    check(x, y+1);
    check(x+1, y);
}

int main(){

     for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            scanf("%1d",&tri[i][j]);
        }
    }

    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++){
            if(tri[i][j] == 1 && vt[i][j] == 0){
                cnt=v_cnt=t=0;
                check(i,j);
                pii num=triangle();

                ver(i, j);
                if(num.first == 1){
                    if(v_cnt != 3) break;

                    sort(v+1,v+v_cnt+1);
                    int x1=v[1].first, x2=v[2].first, x3=v[3].first, y1=v[1].second, y2=v[2].second, y3=v[3].second;

                    if(y1 != y3){
                        ///1번째
                        if(x2 == x3){
                            int h_l=y1-1, h_r=y1+1, b=0;
                            for(int i=x1;i<=x2;i++){
                                for(int j=h_l;j<=h_r;j++){
                                    if(j == h_l && tri[i][j] == 1 || j == h_r && tri[i][j] == 1 || j != h_l && j != h_r && tri[i][j] == 0){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h_l--,h_r++;
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }

                        ///2번째
                        else if(x1 == x2){
                            int h_l=y1-1, h_r=y2+1, b=0;
                            for(int i=x1;i<=x2;i++){
                                for(int j=h_l;j<=h_r;j++){
                                    if(j == h_l && tri[i][j] == 1 || j == h_r && tri[i][j] == 1 || j != h_l && j != h_r && tri[i][j] == 0){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h_l++,h_r--;
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }
                    }

                    else if(y1 == y3){
                        ///3번째
                        if(y2 < y1){
                            int h=y1-1, p=1, b=0;
                            for(int i=x1;i<=x3;i++){
                                for(int j=h;j<=y1;j++){
                                    if(j == h && tri[i][j] == 1 ||  j != h && tri[i][j] == 0){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h-=p;
                                if(h == y2-2){
                                    h=y2;
                                    p=-1;
                                }
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }

                        ///4번째
                        else if(y2 > y1){
                            int h=y1+1, p=1, b=0;
                            for(int i=x1;i<=x3;i++){
                                for(int j=y1;j<=h;j++){
                                    if(j == h && tri[i][j] == 1 ||  j != h && tri[i][j] == 0){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h+=p;
                                if(h == y2+2){
                                    h=y2;
                                    p=-1;
                                }
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }
                    }
                }

                else if(num.first == 2){
                    int x1=v[1].first, x2=v[2].first, x3, y1=v[1].second, y2=v[2].second, y3;

                    if(v_cnt != 2 || tri[x1][y2] + tri[x2][y1] != 1) break;

                    if(tri[x1][y2] == 1) v[++v_cnt]=make_pair(x1,y2);
                    else v[++v_cnt]=make_pair(x2,y1);

                    sort(v+1,v+v_cnt+1);

                    x1=v[1].first, x2=v[2].first, x3=v[3].first, y1=v[1].second, y2=v[2].second, y3=v[3].second;

                    if(x1 != x2){
                        ///5번째
                        if(y1 == y2){
                            int h=y1+1, b=0;
                            for(int i=x1;i<=x2;i++){
                                for(int j=y1;j<=h;j++){
                                    if(j != h && tri[i][j] == 0 || j == h && tri[i][j] == 1){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h++;
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }

                        ///6번째
                        else if(x2 == x3){
                            int h=y1-1, b=0;
                            for(int i=x1;i<=x2;i++){
                                for(int j=h;j<=y2;j++){
                                    if(j != h && tri[i][j] == 0 || j == h && tri[i][j] == 1){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h--;
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }
                    }

                    else if(x1 != x3){
                        ///7번째
                        if(y1 == y3){
                            int h=y2+1, b=0;
                            for(int i=x1;i<=x3;i++){
                                for(int j=y1;j<=h;j++){
                                    if(j != h && tri[i][j] == 0 || j == h && tri[i][j] == 1){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h--;
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }

                        ///8번째
                        else if(y2 == y3){
                            int h=y1-1, b=0;
                            for(int i=x1;i<=x3;i++){
                                for(int j=h;j<=y2;j++){
                                    if(j != h && tri[i][j] == 0 || j == h && tri[i][j] == 1){
                                        b=1;
                                        break;
                                    }
                                }
                                if(b == 1) break;
                                h++;
                            }
                            if(b == 1) break;
                            printf("%d %d\n",x1,y1);
                            printf("%d %d\n",x2,y2);
                            printf("%d %d",x3,y3);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    printf("0");
    return 0;
}