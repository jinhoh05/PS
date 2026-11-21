#include <bits/stdc++.h>

using namespace std;

int n;
string s[20005];
vector<string> v;

bool comp(string a, string b){
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> s[i];
    }

    sort(s + 1, s + n + 1, comp);

    for(int i=1;i<=n;i++){
        int k = 0;
        for(int j=1;j<i;j++){
            if(s[j] == s[i]){
                k = 1;
                break;
            }
        }

        if(k) continue;

        cout << s[i] << "\n";
    }

    return 0;
}
