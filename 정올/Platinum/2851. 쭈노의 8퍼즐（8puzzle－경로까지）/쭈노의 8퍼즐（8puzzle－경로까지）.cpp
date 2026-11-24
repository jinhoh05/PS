#include <bits/stdc++.h>

using namespace std;
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int head, tail;
set<int> puz;

struct data{
    int lev, p9, pn, path;
    int i,j;
    int a[3][3];
    int getcode(){
        int i,j,code=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                code=code*10+a[i][j];
                if(a[i][j]==9) p9=i*3+j;
            }
        }
        return code;
    }

    int move(int x,int y,int p){
        int r=p9/3,c=p9%3;
        int nx=r+x;
        int ny=c+y;
        if(nx < 0 || nx > 2 || ny < 0 || ny > 2) return 0;
        path=p;
        pn=a[nx][ny];
        swap(a[r][c],a[nx][ny]);
        lev++;
        return 1;
    }
}que[1<<20];

int push(data&r){
    int code=r.getcode();
    if(puz.count(code)) return 0;
    puz.insert(code);
    if(code==123456789) return 1;
    tail++;
    return 0;
}

int bfs(){
    while(head < tail){
        for(int i=0;i<4;i++){
            que[tail]=que[head];
            if(que[tail].move(dx[i],dy[i],head)){
                if(push(que[tail])) return tail;
            }
        }
        head++;
    }
    return 0;
}

void track(int idx){
    if(idx==0) return;
    track(que[idx].path);
    printf("%d ",que[idx].pn);
}

int main()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            char tmp;
            scanf(" %c",&tmp);
            if(tmp == 'X'){
                que[0].a[i][j]=9;
                que[0].p9 = i*3+j;
            }
            else que[0].a[i][j]=tmp-'0';
        }
    }

    if(push(que[0])) {
        puts("0");
        return 0;
    }

    int ans=bfs();
    printf("%d\n",que[ans].lev);
    track(ans);

    return 0;
}