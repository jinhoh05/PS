#include <bits/stdc++.h>

using namespace std;
int n,m;
int monkey[25];
int vt[1<<22];
string ans;

struct data{
    int mong;
    string path;
    data(){}
    data(int _mong,string _path){
        mong=_mong,path=_path;
    }
};

int bfs(){
    queue<data>que;
    while(!que.empty()) que.pop();
    memset(vt,0,sizeof(vt));
    que.push(data((1 << n) - 1,""));
    vt[(1<<n)-1]=1;

    while(!que.empty()){
        data t=que.front();
        que.pop();
        for(int i=0;i<n;i++){
            if(t.mong & (1<<i)){
                int mong=t.mong ^ (1<<i);
                int newmong=0;
                for(int j=0;j<n;j++){
                    if(mong & (1<<j)) newmong |= monkey[j];
                }
                if(vt[newmong]) continue;
                vt[newmong]=1;
                char ch=i + '0';
                string tmp=ch+t.path;
                if(newmong==0){
                    ans=tmp;
                    return 1;
                }
                que.push(data(newmong,tmp));
            }
        }
    }
    return 0;
}

void answer() {
    if((m > n - 1) || bfs()==0) printf("Impossible\n");
    else{
        printf("%d:", ans.length());
        for(int i=ans.length()-1;i>=0;i--){
            printf(" %d", ans[i] - '0');
        }
        printf("\n");
    }
    return;
}

int main()
{
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) return 0;
        memset(monkey,0,sizeof(monkey));
        for(int i=1;i<=m;i++){
            int v,u;
            scanf("%d %d",&v,&u);
            monkey[v] |= (1 << u);
            monkey[u] |= (1 << v);
        }
        answer();
    }

    return 0;
}