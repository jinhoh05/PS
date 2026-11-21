#include <bits/stdc++.h>
 
using namespace std;
int square[5][5],ans=8;
 
struct st{
    int a,b,c;
}res[10],re[10];
 
int count_(){
    int cnt=0,sum=1;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(square[i][j] == sum) cnt++;
            sum++;
        }
    }
 
    return cnt;
}
 
void Rotate(int k,int p){
    if(k==1){
        int tmp=square[p][4];
        for(int i=4;i>1;i--){
            square[p][i]=square[p][i-1];
        }
        square[p][1]=tmp;
    }
    else{
        int tmp=square[4][p];
        for(int i=4;i>1;i--){
            square[i][p]=square[i-1][p];
        }
        square[1][p]=tmp;
    }
}
 
int output(){
    printf("%d\n",ans);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            printf("%d ",square[i][j]);
        }
        printf("\n");
    }
}
 
void dfs(int lev){
    int cnt=count_();
 
    if((ans-lev)*4+cnt<16) return;
 
    if(cnt==16){
        ans=lev-1;
        for(int i=1;i<=ans;i++){
            re[i]=res[i];
        }
        //output();
        return;
    }
 
    int i,j,k;
    for(k=1;k<=2;k++){
        for(i=1;i<=4;i++){
            for(j=1;j<4;j++){
                Rotate(k,i);
                res[lev]={k,i,j};
                dfs(lev+1);
            }
            Rotate(k,i);
        }
    }
 
    return;
}
 
int main()
{
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            scanf("%d",&square[i][j]);
        }
    }
 
    dfs(1);
 
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++){
        printf("%d %d %d\n",re[i].a,re[i].b,re[i].c);
    }
 
    return 0;
}