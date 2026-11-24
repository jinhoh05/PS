#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int m, len;
int kmp[400005];

vector<int> v;

string s;

void f(){
    int i=0, j=-1;
    kmp[0]=-1;

    while(i<len){
        if(j==-1 || s[i]==s[j]){
            i++;
            j++;
            kmp[i]=j;
        }

        else j=kmp[j];
    }
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);

    cin >> s;

    len = s.size();
    f();

    v.push_back(len);

    int i=len;
    while(kmp[i]>0){
        v.push_back(kmp[i]);
        i=kmp[i];
    }

    reverse(v.begin(), v.end());
    for(int u : v) cout << u << " ";

    return 0;
}
