#include <bits/stdc++.h>

using namespace std;
int n,ans;
string s;

int main()
{
    cin >> n >> s;
    s='0' + s;

    char a = s[1];
    for(int i=1;i<=n;i++){
        if(a == 'w' && s[i] != 'w') a=s[i];
        if(s[i] == a || s[i] == 'w') ans++;
        else break;
    }

    if(ans == n){
        printf("%d",n);
        return 0;
    }

    for(int i=1;i<n;i++){
        int cnt = 0, j = i;
        a = s[i];

        while(1){
            if(a == 'w' && s[j] != 'w') a = s[j];
            if(s[j] == a || s[j] == 'w') cnt++;
            else break;
            j--;
            if(j == 0) j = n;
        }

        j = i + 1;
        a = s[i + 1];
        while(1){
            if(a == 'w' && s[j] != 'w') a = s[j];
            if(s[j] == a || s[j] == 'w') cnt++;
            else break;
            j++;
            if(j > n) j = 1;
        }

        ans=max(ans, cnt);
    }

    cout << ans;
    return 0;
}