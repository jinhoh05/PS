#include <bits/stdc++.h>

using namespace std;

int n, k, stop;

string s, e, ans;

vector<string> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> k >> n;

    for(int i=0;i<k;i++) s.push_back('A' + i);

    cin >> e;

    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        v.push_back(a);
        if(a[0] == '?') stop = i;
    }

    for(int i=0;i<stop;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == '-') swap(s[j], s[j + 1]);
        }
    }

    for(int i=n-1;i>stop;i--){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j] == '-') swap(e[j], e[j + 1]);
        }
    }

    bool flag = true;
    for(int i=0;i<k-1;i++){
        if(s[i] == e[i]) ans.push_back('*');

        else if(s[i] == e[i + 1] && s[i + 1] == e[i]){
            ans.push_back('-');
            swap(s[i], s[i + 1]);
        }

        else{
            flag = false;
            break;
        }
    }

    if(!flag){
        for(int i=0;i<k-1;i++) cout << 'x';
    }

    else cout << ans;

    return 0;
}
