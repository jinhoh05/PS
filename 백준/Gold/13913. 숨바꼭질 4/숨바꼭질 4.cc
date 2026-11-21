#include <bits/stdc++.h>

using namespace std;

int n, k;
int vt[100005], path[100005];

deque<int> dq;

vector<int> v;

int bfs(){
    dq.push_back(n);
    vt[n] = 1;
    path[n] = n;

    while(!dq.empty()) {
        int loc = dq.front();
        dq.pop_front();

        if(loc == k) return vt[k] - 1;

        if(loc*2 <= 100000 && !vt[loc*2]) {
            dq.push_front(loc*2);
            vt[loc*2] = vt[loc]+1;
            path[loc*2] = loc;
        }

        if(loc-1 >= 0 && !vt[loc-1]) {
            dq.push_back(loc-1);
            vt[loc-1] = vt[loc]+1;
            path[loc-1] = loc;
        }

        if(loc+1 <= 100000 && !vt[loc+1]) {
            dq.push_back(loc+1);
            vt[loc+1] = vt[loc]+1;
            path[loc+1] = loc;
        }
    }
}

void find_path(int loc){
    v.push_back(loc);
    if(loc == n) return;
    find_path(path[loc]);
}

int main() {

    scanf("%d %d", &n, &k);

    printf("%d\n", bfs());

    find_path(k);

    reverse(v.begin(), v.end());

    for(int u : v){
        printf("%d ", u);
    }

    return 0;
}
