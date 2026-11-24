#include <bits/stdc++.h>

using namespace std;
int hanoi4[25],hanoi3[25];
int f4[25],f3[25];
int ans=1234567,small=0;
int t,n;
char a[6]={'0','A','B','C','D'};

void dfs3(int n,int s,int e,int b,int up){
    if(n <= 0) return;
    dfs3(n-1,s,b,e,up);
    printf("%d : %c->%c\n",n+up,a[s],a[e]);
    dfs3(n-1,b,e,s,up);
}


void dfs4(int n,int s,int e,int b1,int b2){
    if(n <= 0) return;

    dfs4(f4[n],s,b1,e,b2);
    dfs3(f3[n],s,e,b2,f4[n]);
    dfs4(f4[n],b1,e,s,b2);
}

int main()
{
    hanoi4[1]=hanoi3[1]=1;

    for(int i=2;i<=20;i++){
        ans=1234567,small=0;
        for(int k=1;k<i;k++){
            small=2 * hanoi4[i-k] + hanoi3[k];
            ans=min(ans,small);
        }
        hanoi3[i]=(1<<i)-1;
        hanoi4[i]=ans;
    }

    scanf("%d",&n);

    f4[1]=0;
    f3[1]=1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(2*hanoi4[j]+hanoi3[i-j]==hanoi4[i]){
                f4[i]=j;
                f3[i]=i-j;
                break;
            }
        }
    }


    printf("%d\n",hanoi4[n]);

    dfs4(n,1,4,2,3);

    return 0;
}