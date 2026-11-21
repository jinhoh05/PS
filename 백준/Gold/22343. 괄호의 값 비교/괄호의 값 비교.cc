#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, l;
int t;

vector<int> check(string s){
    vector<int> v(l+1);
    int sc=0;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') sc++;

        else{
            sc--;
            if(s[i-1] == '('){
                v[sc]++;
            }
        }
    }

    for(int i=0; i<v.size()-1; i++){
        v[i+1]+=v[i]/2;
        v[i]%=2;
    }

    return v;
}

string check2(string s1, string s2){
    vector<int> a = check(s1);
    vector<int> b = check(s2);

    for(int i=a.size()-1; i>=0; i--){
        if(a[i] < b[i]) return "<";
        if(a[i] > b[i]) return ">";
    }

    return "=";
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        string s1, s2;
        cin >> s1 >> s2;

        l=max(s1.size(), s2.size());
        l/=2;

        cout << check2(s1, s2) << "\n";
    }

    return 0;
}
