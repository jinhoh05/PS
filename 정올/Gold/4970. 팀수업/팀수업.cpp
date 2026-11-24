#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, M;
int stu[2505];

ll student[55][55];
ll vt[55][55];
ll dist[2505];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pll> v[2505];

struct Data{

    int x, y;

    ll sp;

    bool operator<(const Data& t)const{
        return sp < t.sp;
    }
};

Data ans, comp;

void dijk(int st)
{
    for(int i=1; i<=N*M; i++) dist[i] = LLONG_MAX;
    dist[st] = 0;
	priority_queue<pll> pq;

    pq.push({0, st});

    while(!pq.empty())
    {
        ll cost = -pq.top().first;
        ll cur = pq.top().second;
        pq.pop();

        if(dist[cur] < cost) continue;

        for(int i=0; i<v[cur].size(); i++){
            ll next_cur = v[cur][i].first;
            ll next_dist = cost + v[cur][i].second;

            if(dist[next_cur] > next_dist){
                dist[next_cur] = next_dist;
                pq.push({-next_dist, next_cur});
            }
        }
    }

/*
    int cnt=1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            printf("%d ", dist[cnt++]);
        }
        printf("\n");
    }
*/
    ll sum=0, num=0;
    for(int i=1; i<=N*M; i++){
        if(sum < dist[i]){
            sum = dist[i];
            num = i;
        }
    }

    if(ans.sp > sum) ans = {N-1, st-1, sum};
}

void check(){
    int cnt=1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(cnt%M != 0) v[cnt].push_back({cnt+1, stu[cnt]});
            if(cnt%M != 1) v[cnt].push_back({cnt-1, stu[cnt]});
            if(cnt+M <= M*N) v[cnt].push_back({cnt+M, stu[cnt]});
            if(cnt-M >= 1) v[cnt].push_back({cnt-M, stu[cnt]});
            cnt++;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%lld", &student[i][j]);
        }
    }

    int cnt=1;
    for(int i=N; i>=1; i--){
        for(int j=1; j<=M; j++){
            stu[cnt++] = student[i][j];
        }
    }

    check();

    ans.sp = LLONG_MAX;

    for(int i = 1; i <= M; i++)
    {
        dijk(i);
    }

    printf("%d %d\n%lld", ans.x, ans.y, ans.sp);

    return 0;
}
