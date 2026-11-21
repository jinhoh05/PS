#include <bits/stdc++.h>

using namespace std;

char s[10];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> s;

    sort(s, s + strlen(s), greater<int>());

    for(int i=0;i<strlen(s);i++) cout << s[i];

    return 0;
}
