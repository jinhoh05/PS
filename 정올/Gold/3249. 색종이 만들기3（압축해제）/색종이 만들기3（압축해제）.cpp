#include <bits/stdc++.h>

using namespace std;
int n,cnt;
char square[1030][1030];
char s[2000005];

int put(int num,int lx,int ly,int rx,int ry){
    for(int i=lx;i<=rx;i++){
        for(int j=ly;j<=ry;j++){
            square[i][j]=num;
        }
    }
    return 0;
}

void check(int lx,int ly,int rx,int ry){
    int mx=(rx+lx)/2,my=(ry+ly)/2;
    if(cnt >= strlen(s)) return;
    char ch=s[cnt++];
    if(ch == 'X'){
        check(lx,ly,mx,my);
        check(lx,my+1,mx,ry);
        check(mx+1,ly,rx,my);
        check(mx+1,my+1,rx,ry);
    }
    else{
        put(ch,lx,ly,rx,ry);
    }
    return;
}

int main()
{
    cin >> n >> s;

    check(1,1,n,n);
    
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c ",square[i][j]);
        }
        printf("\n");
    }

    return 0;
}