#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int c, n;
int bit[100005];

string s;

vector<int> dist;

queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;
    for(int i=0; i<n; i++){
        cin >> s;
        bit[i] = 0;
        
        for(char h : s){
            bit[i] *= 2;
            if(h == 'G') bit[i]++;
        }
    }

    dist.resize(1 << c, -1);
    for(int i=0; i<n; i++){
        if(dist[bit[i]] == -1) {
            dist[bit[i]] = 0;
            q.push(bit[i]);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<c; i++){
            int next = cur ^ (1 << i);

            if(dist[next] == -1){
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    int mx = (1 << c) - 1;
    for(int i=0; i<n; i++){
        int op = bit[i] ^ mx;
        cout << c - dist[op] << '\n';
    }

    return 0;
}