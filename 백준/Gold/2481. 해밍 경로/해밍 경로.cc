#include <bits/stdc++.h>
 
using namespace std;

int n,k,m,p;
int path[100010],vt[100010];
int where[100010];

struct st{
    int lev,code;
    bool operator<(const st& t)const{
        return code < t.code;
    }
}arr[100010];

queue<int>que;
 
int output(int x){
    if(x == 0) return 1;
    if(path[x]==0 && x != p) return 0;
    if(output(path[x]) == 0) return 0;
    
    printf("%d ",arr[x].lev);
    
    return 1;
}
 
void push(int x){
    for(int j=0;j<k;j++){
        int num = arr[x].code ^ (1 << j);
        st tmp;
        tmp.code=num;
        int pos=lower_bound(arr+1,arr+n+1,tmp)-arr;
        if(vt[pos] == 0 && arr[pos].code == num){
            vt[pos]=1;
            path[pos]=x;
            que.push(pos);
        }
    }
 
}
 
int bfs(){
    p=where[1];
    push(p);
    vt[p]=1;
    path[p]=0;
    int t;
    while(!que.empty()){
        t=que.front();
        que.pop();
        push(t);
    }
    return 0;
}
 
int main()
{
    //freopen("input.txt","r",stdin);
 
    scanf("%d %d",&n,&k);
 
    int num;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            scanf("%1d",&num);
            arr[i].code=arr[i].code*2+num;
        }
        arr[i].lev=i;
    }
 
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        where[arr[i].lev]=i;
    }
 
    bfs();
 
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        if(output(where[num])==0) printf("-1 ");
        printf("\n");
    }
 
    return 0;
}