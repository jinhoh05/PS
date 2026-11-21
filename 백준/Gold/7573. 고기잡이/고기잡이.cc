#include <bits/stdc++.h>
 
using namespace std;
 
int n,l,m,r;
pair<int,int> f[101];
 
bool chk(int x,int y,int lx,int ly,int rx,int ry) {
    return lx<=x && x<=rx && ly<=y && y<=ry;
}
 
int counting(int lx,int ly,int rx,int ry) {
    int cnt=0;
    for(int i=1;i<=m;i++){
        cnt+=chk(f[i].first,f[i].second,lx,ly,rx,ry);
    }
    return cnt;
}
 
void net(pair<int,int> p) {
    for(int k=1;k<l;k++) {
        int nx=k;
        int ny=l-k;
        for(int i=p.first-nx;i<=p.first;i++) {
            for(int j=p.second-ny;j<=p.second;j++) {
                r=max(r,counting(i,j,i+nx,j+ny));
            }
        }
    }
}
 
int main() {
    scanf("%d %d %d",&n,&l,&m);
    l/=2;
 
    for(int i=1;i<=m;i++){
        scanf("%d %d", &f[i].first,&f[i].second);
    }
 
    for(int i=1;i<=m;i++){
        net(f[i]);
    }
 
    printf("%d",r);
    return 0;
}