#include <bits/stdc++.h>

using namespace std;
int n,fr[10005],to[10005];
int DP[10010][15],Dir[10010][15],Cost[10010][15];

///DP[i][j]=j번 왼쪽으로 돌렸을때 i번째 나사를 맞추기 위한 최솟값
///Dir : 어느쪽으로 돌았는지 저장하는 배열
///Cost : 몇번 돌았는지를 저장하는 배열

///A숫자나사를 B숫자나사로 맞출때
///왼쪽으로 돌릴때 : (B-A+10) % 10
///오른쪽으로 돌릴때 : (A-B+10) % 10

int solve(int idx, int turn){
    if(idx == n) return 0;

    int &ret = DP[idx][turn];
    if(ret != -1) return ret;

    ///현재 내가 왼쪽으로 돌렸을때 보고 있는 수
    int cur = (fr[idx] + turn) % 10;

    ///왼쪽으로 돌린뒤 추가적으로 돌릴때
    int l_turn = (to[idx] - cur + 10) % 10;
    int l_cost = solve(idx + 1, (turn + l_turn) % 10) + l_turn;

    int r_turn = (cur - to[idx] + 10) % 10;
    int r_cost = solve(idx + 1, turn) + r_turn;

    ///왼쪽으로 돌릴때랑 오른쪽으로 돌릴때중 최솟값 판별
    if(r_cost > l_cost){
        ret = l_cost;
        Dir[idx][turn] = 1;
        Cost[idx][turn] = l_turn;
    }

    else{
        ret = r_cost;
        Dir[idx][turn] = -1;
        Cost[idx][turn] = r_turn;
    }

    return ret;
}

void path(int idx,int turn) {
    if(idx == n) return;

    int m = Dir[idx][turn] * Cost[idx][turn];

    if(m != 0) printf("%d %d\n",idx+1, m);
    else printf("%d 0\n",idx+1);

    if(Dir[idx][turn] > 0) path(idx + 1, (turn + m + 10) % 10);
    else path(idx + 1, turn);
}

int main()
{
    memset(DP,-1,sizeof(DP));

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%1d",&fr[i]);
    for(int i=0;i<n;i++) scanf("%1d",&to[i]);

    printf("%d\n",solve(0,0));
    path(0,0);

    return 0;
}