#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int x,y,z;
int table[105][105];
int composite[105];

void toy(int k,int cnt){
    if(composite[k]==0){
        table[k][0]+=cnt;
        return;
    }
    for(int i=1;i<n;i++){
        if(table[k][i]) {
            toy(i,cnt*table[k][i]);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);

    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        table[x][y]=z;
        composite[x]=1;
    }
    toy(n, 1);

    for(int i=1;i<=n;i++){
        if(composite[i]==0){
            printf("%d %d\n", i, table[i][0]);
        }
    }

    return 0;
}