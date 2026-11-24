#include <bits/stdc++.h>

using namespace std;
int win[10],draw[10],lose[10];
int win1[10],draw1[10],lose1[10];
int cnt;

int dfs(int a,int b){
    if(b>6){
        if(win[a] != win1[a] || draw[a] != draw1[a] || lose[a] != lose1[a]) return 0;
        a++;
        b=a+1;
    }
    
    if(a==6) return (win[a] == win1[a] && draw[a] == draw1[a] && lose[a] == lose1[a]);
    
    win1[a]++, lose1[b]++;
    if(dfs(a,b+1)) return 1;
    win1[a]--, lose1[b]--;

    draw1[a]++, draw1[b]++;
    if(dfs(a,b+1)) return 1;
    draw1[a]--, draw1[b]--;

    win1[b]++, lose1[a]++;
    if(dfs(a,b+1)) return 1;
    win1[b]--, lose1[a]--;

    return 0;
}

int main()
{
   // freopen("input.txt","r",stdin);
    
    for(int i=1;i<=4;i++){
        memset(win1,0,sizeof(win1));
        memset(draw1,0,sizeof(draw1));
        memset(lose1,0,sizeof(lose1));

        for(int j=1;j<=6;j++){
            scanf("%d %d %d",&win[j],&draw[j],&lose[j]);
        }
        
        if(dfs(1,2)) printf("1 ");
        else printf("0 ");
    }

    return 0;
}