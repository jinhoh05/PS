#include <bits/stdc++.h>

using namespace std;

int n, k;
int vt[100005];

deque<int> dq;

int bfs(){
    dq.push_back(n);
    vt[n] = 1;

    while(!dq.empty()) {
        int loc = dq.front();
        dq.pop_front();

        if(loc == k) return vt[k] - 1;

        if(loc*2 <= 100000 && !vt[loc*2]) {
            dq.push_front(loc*2);
            vt[loc*2] = vt[loc];
        }

        if(loc-1 >= 0 && !vt[loc-1]) {
            dq.push_back(loc-1);
            vt[loc-1] = vt[loc]+1;
        }
        
        if(loc+1 <= 100000 && !vt[loc+1]) {
            dq.push_back(loc+1);
            vt[loc+1] = vt[loc]+1;
        }
    }
}

int main() {

    scanf("%d %d", &n, &k);

    printf("%d", bfs());

    return 0;
}
