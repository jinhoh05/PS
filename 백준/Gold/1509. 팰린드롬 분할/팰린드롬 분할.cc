#include <bits/stdc++.h>

using namespace std;

string s;
int palin[2505][2505];
int DP[2505];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> s;
    s.insert(0, " ");

    int len = s.size();

    for(int i=1;i<=len;i++) palin[i][i] = 1;

    for(int i=1;i<len;i++){
        if(s[i] == s[i + 1]) palin[i][i + 1] = 1;
    }

    for(int i=2;i<len;i++){
        for(int j=1;j<=len-i;j++){
            if(s[j] == s[i + j] && palin[j + 1][j + i - 1]) palin[j][j + i] = 1;
        }
    }

    for(int i=1;i<len;i++){
        DP[i] = INT_MAX;
        for(int j=1;j<=i;j++){
            if(palin[j][i]) DP[i] = min(DP[i], DP[j - 1] + 1);
        }
    }

    cout << DP[len - 1];

    return 0;
}
