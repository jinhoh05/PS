#include <bits/stdc++.h>

using namespace std;

///. DP[i] = max(DP[i + 1], DP[j] + i번회의 인원)
///    - i번 회의를 안하는 경우와 i번 회의를 하는 경우중 큰값
///    - j = i번 회의보다 시작 시간이 큼 && i번 회의와 안겹침 && 시작 시간이 가장 작은 회의 번호
///. 정답 = DP[1]

struct st{
    int s, e, c;
    bool operator<(const st &t)const{
        if(s == t.s) return e < t.e;
        return s < t.s;
    }

}room[100005];

const int INF = 987654321;
int n, ans;
st DP[100005];

int binary_search(int val, int l, int r){
    if(l > r) return -INF;

    int mid = (l + r) / 2;

    if(DP[mid].s >= val && DP[mid - 1].s < val) return mid;

    else if(val <= DP[mid].s) return binary_search(val, l, mid - 1);

    else return binary_search(val, mid + 1, r);

    return -INF;
}

void dynamic(){
    DP[n] = room[n];

    for(int i=n-1;i>=1;i--){
        int j = binary_search(room[i].e, i + 1, n);

        if(room[i].c > DP[i + 1].c) DP[i] = room[i];
        else DP[i] = DP[i + 1];

        if(j == -INF) continue;

        if(DP[i].c <= DP[j].c + room[i].c){
            DP[i] = room[i];
            DP[i].c += DP[j].c;
        }
    }
}

int main()
{
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        scanf("%d %d %d", &room[i].s, &room[i].e, &room[i].c);
    }

    sort(room + 1, room + n + 1);

    dynamic();

    printf("%d", DP[1].c);

    return 0;
}
