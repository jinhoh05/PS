#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans=-1, k, s, mv=1;
int vt[2][500005];

vector<int> v;

queue<int> q;

void bfs(){
    q.push(n);

    while(!q.empty()){
        k += mv;

        if(k > 500000){
            ans = -1;
            return;
        }

        if(vt[mv%2][k]){
            ans = mv;
            return;
        }

        int sz = q.size();
        for(int i=0; i<sz; i++){
            int loc=q.front();
            q.pop();

            for(int n_loc : {loc-1, loc+1, loc*2}){
                if(n_loc == k){
                    ans = mv;
                    return;
                }

                if(n_loc < 0 || n_loc > 500000) continue;
                if(vt[mv%2][n_loc]) continue;
                vt[mv%2][n_loc] = 1;
                q.push(n_loc);
            }
        }
        mv++;
    }
}

int main(){

    scanf("%d %d", &n, &k);

    if(n == k){
        printf("0");
        return 0;
    }

    bfs();

    printf("%d", ans);

    return 0;
}
