#include<bits/stdc++.h>

using namespace std;

int l, c;
char pw[16];

void find_pw(int x, int cnt, int vow, int con, string s) {
    if(cnt == l){
        if(vow >= 1 && con >= 2) cout << s << "\n";
        return;
    }

    if(x == c) return;

    if(pw[x] == 'a' || pw[x] == 'e' || pw[x] == 'i' || pw[x] == 'o' || pw[x] == 'u'){
        find_pw(x + 1, cnt + 1, vow + 1, con, s + pw[x]);
    }

    else find_pw(x + 1, cnt + 1, vow, con + 1, s + pw[x]);

    find_pw(x + 1, cnt, vow, con, s);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> l >> c;

    for(int i=0;i<c;i++) cin >> pw[i];

    sort(pw, pw + c);

    find_pw(0, 0, 0, 0, "");

    return 0;
}
