#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 100000;
int n, k;
int vt[INF + 5];
queue<int> q;

void push(int x){
    if(x - 1 >= 0 && vt[x - 1] == 0){
        vt[x - 1] = vt[x] + 1;
        q.push(x - 1);
    }

    if(x + 1 <= INF && vt[x + 1] == 0){
        vt[x + 1] = vt[x] + 1;
        q.push(x + 1);
    }

    if(2 * x <= INF && vt[2 * x] == 0){
        vt[2 * x] = vt[x] + 1;
        q.push(x * 2);
    }

}

int bfs(){
    q.push(n);
    vt[n] = 1;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        if(t == k) return vt[t] - 1;

        push(t);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;

    cout << bfs();

    return 0;
}
