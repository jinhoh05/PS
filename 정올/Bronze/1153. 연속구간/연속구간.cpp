#include <bits/stdc++.h>

using namespace std;
string s;
int ans,longest,x,y;

int main()
{
    //freopen("input.txt","r",stdin);

    for(int i=1;i<=3;i++){
        ans=longest=1;
        cin >> s;
        for(int j=0;j<s.size();j++){
            while(s[j] == s[j+1]){
                ans++;
                j++;
            }
            longest=max(ans,longest);
            ans=1;
        }
        printf("%d\n",longest);
    }

    return 0;
}