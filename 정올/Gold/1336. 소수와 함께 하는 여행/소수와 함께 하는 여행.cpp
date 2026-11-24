#include <bits/stdc++.h>
  
using namespace std;
int n,m,sum;
int prime[10005];
int vt[10005];
  
struct data{
    int x,lev;
};
queue <data>que;
  
int eratos(){
    for(int i=2;i*i<=10000;i++){
        if(prime[i] == 0){
            for(int j=i*i;j<=10000;j+=i){
                prime[j]=1;
            }
        }
    }
}
  
void push(int x,int y,int number,int lev){
    int cnt=0;
  
    if(x==1){
        cnt = (y*1000) + (number % 1000);
        if(cnt == m){
            printf("%d",lev);
            sum=1;
            return;
        }
        if(vt[cnt]) return;
        vt[cnt]=1;
        if(prime[cnt] == 0) que.push({cnt,lev});
        return;
    }
  
    else if(x==2){
        cnt = (number - (((number / 100) % 10) * 100)) + (y * 100);
        if(cnt == m){
            printf("%d",lev);
            sum=1;
            return;
        }
        if(vt[cnt]) return;
        vt[cnt]=1;
        if(prime[cnt] == 0) que.push({cnt,lev});
        return;
    }
  
    else if(x==3){
        cnt = (number - (((number / 10) % 10) * 10)) + (y * 10);
        if(cnt == m){
            printf("%d",lev);
            sum=1;
            return;
        }
        if(vt[cnt]) return;
        vt[cnt]=1;
        if(prime[cnt] == 0) que.push({cnt,lev});
        return;
    }
  
    else if(x==4){
        cnt = (number - (number % 10)) + y;
        if(cnt == m){
            printf("%d",lev);
            sum=1;
            return;
        }
        if(vt[cnt]) return;
        vt[cnt]=1;
        if(prime[cnt] == 0) que.push({cnt,lev});
        return;
    }
  
}
  
int bfs(){
    data t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        for(int i=1;i<=4;i++){
           for(int j=0;j<=9;j++){
               if(i == 1 && j == 0) continue;
               push(i,j,t.x,t.lev+1);
               if(sum == 1) return 0;
           }
        }
    }
  
}
  
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
  
    scanf("%d %d",&n,&m);
    prime[1]=1;
    vt[n]=1;
    eratos();
  
    que.push({n,0});
    bfs();
  
    return 0;
}