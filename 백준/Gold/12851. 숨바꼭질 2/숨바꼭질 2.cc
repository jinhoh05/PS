#include <bits/stdc++.h>

using namespace std;

int n, k, ans, length=INT_MAX;
int vt[100005];

bool flag = false;

queue<pair<int, int>> q;

void bfs(){
    q.push({n, 0});
    vt[n] = 1;

    while(!q.empty()) {
        int loc = q.front().first;
        int dist = q.front().second;
        q.pop();

        vt[loc] = 1;

        if(length < dist) break;

        if(loc == k){
            length = dist;
            ans++;
            continue;
        }

        if(loc+1 <= 100000 && !vt[loc+1]) {
            q.push({loc+1, dist+1});
        }

        if(loc-1 >= 0 && !vt[loc-1]) {
            q.push({loc-1, dist+1});
        }

        if(loc*2 <= 100000 && !vt[loc*2]) {
            q.push({loc*2, dist+1});
        }
    }
}

int main() {

    scanf("%d %d", &n, &k);

    bfs();

    printf("%d\n%d", length, ans);

    return 0;
}
