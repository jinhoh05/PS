#include <bits/stdc++.h>
using namespace std;

int a[110],b[110],c[110];
int q[110],w[110],e[110];
int check[10][10][10];
int n;

int strikecheck(int c1, int c2, int c3, int gnum)
{
    int s = 0;
    if(c1 == q[gnum]) s++;
    if(c2 == w[gnum]) s++;
    if(c3 == e[gnum]) s++;
    return s;
}

int ballcheck(int c1, int c2, int c3, int gnum)
{
    int sb = 0;
    if(c1 == e[gnum] || c1 == w[gnum]) sb++;
    if(c2 == q[gnum] || c2 == e[gnum]) sb++;
    if(c3 == q[gnum] || c3 == w[gnum]) sb++;
    return sb;
}

int main()
{
    int cnt=0;
    int ball[110];
    int r,t,y;
    int s,sb,ans = 9*8*7;

    scanf("%d",&n);
    int f;

    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        q[i]=a[i]/100;
        w[i]=a[i]/10%10;
        e[i]=a[i]%10;
    }
    for(int f=1;f<=n;f++){
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                if(i==j) continue;
                for(int k=1;k<=9;k++){
                    if(i == k || j == k) continue;
                    if(check[i][j][k] == 1) continue;
                    
                    s = strikecheck(i,j,k,f);
                    sb = ballcheck(i,j,k,f);

                    if(s != b[f] || sb != c[f]){
                       check[i][j][k] = 1;
                       ans--;
                    }
                }
            }
        }
    }
    printf("%d",ans);

    return 0;
}