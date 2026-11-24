#include <bits/stdc++.h>
using namespace std;

struct Data{
    string op;
    char l, r;
};

int n;
int a[105];

vector<int> l, r;
vector<Data> ans;

void take(char l, char r){
    ans.push_back({"take", l, r});
};

void put(char l, char r){
    ans.push_back({"put", l, r});
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i];

    for(int i = n - 1; i >= 0; i--){
        l.push_back(a[i]);
    }

    while(!l.empty()){
        int x = l.back();
        l.pop_back();
        take('L', 'L');

        while(!r.empty() && r.back() > x){
            int y = r.back();
            r.pop_back();
            take('R', 'R');
            l.push_back(y);
            put('R', 'L');
        }

        r.push_back(x);
        put('L', 'R');
    }

    while(!r.empty()){
        int x = r.back();
        r.pop_back();
        take('L', 'R');
        l.push_back(x);
        put('L', 'L');
    }

    cout << ans.size() << '\n';
    for(Data &t : ans) {
        cout << t.op << ' ' << t.l << ' ' << t.r << '\n';
    }

    return 0;
}