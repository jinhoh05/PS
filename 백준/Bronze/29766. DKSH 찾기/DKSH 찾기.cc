#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin.tie()->ios_base::sync_with_stdio(0);

    cin >> s;

    int cnt=0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'D' && s[i+1] == 'K' && s[i+2] == 'S' && s[i+3] == 'H') cnt++;
    }

    cout << cnt;

    return 0;
}
