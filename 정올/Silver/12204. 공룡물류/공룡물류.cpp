#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, c;
int a[200005];
int line[200005];

vector<pair<string, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int l = 0, r = 0;

    for(int i=0; i<n; i++){
        int x = a[i];
    
        if(l < x && r < x){
            if(l >= r){
                line[x] = 1;
                l = x;
            }
            else{
                line[x] = 2;
                r = x;
            }
        }
        
        else if(l < x){
            line[x] = 1;
            l = x;
        }

        else if(r < x){
            line[x] = 2;
            r = x;
        }

        else{
            cout << "NO\n";
            return 0;
        }
    }

    int cur = 1;
    for(int i=0; i<n; i++){
        int x = a[i];

        while(cur <= x){
            v.push_back({"IN", line[cur]});
            cur++;
        }

        v.push_back({"OUT", line[x]});
    }

    cout << "YES\n" << n*2 << "\n";
    for(auto &u : v){
        cout << u.first << " " << u.second << "\n";
    }    

    return 0;
}