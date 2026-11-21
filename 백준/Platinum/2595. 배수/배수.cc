#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int prv[100000], vt[100000], mv[100000];

vector<int> com[1<<10];

int check(int bit){
    queue<int> q;

    for(int u : com[bit]) if(u){
        int x = u % n;
        vt[x] = 1;
        q.push(x);
        mv[x] = u;
    }

    while(q.size()){
        int v = q.front();
        q.pop();

        if(!v) return 1;

        for(int u : com[bit]){
            int x = (v * 10 + u) % n;
            if(!vt[x]){
                prv[x] = v;
                mv[x] = u;
                vt[x] = 1;
                q.push(x);
            }
        }
    }

    return 0;
}

void multi(){
    int cnt;
    vector<string> v;

    for(int i=0; i<(1<<10); i++){
        memset(prv, -1, sizeof(prv));
        memset(vt, 0, sizeof(vt));
        if(v.size() && cnt < com[i].size()) break;
        if(check(i)){
            string s;
            for(int j=0; j!=-1; j=prv[j]) s += char(mv[j] + '0');
            reverse(s.begin(), s.end());
            v.push_back(s);
            cnt = com[i].size();
        }
    }

    sort(v.begin(), v.end(), [](const string &a, const string &b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });

    cout << v[0];
}

int main()
{
    scanf("%d", &n);

    for(int i=0; i<(1<<10); i++){
        for(int j=0; j<10; j++){
            if(i & (1<<j)) com[i].push_back(j);
        }
    }

    sort(com, com + 1024, [](const vector<int> &a, const vector<int> &b){
        return a.size() < b.size();
    });

    multi();

    return 0;
}
