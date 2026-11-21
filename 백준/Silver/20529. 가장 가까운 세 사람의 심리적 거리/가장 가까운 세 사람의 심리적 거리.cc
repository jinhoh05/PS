#include <bits/stdc++.h>

using namespace std;

int t, n;
string s[100005];

int Find(int x, int y){
    int cnt = 0;

    for(int d=0;d<4;d++){
        if(s[x][d] != s[y][d]) cnt++;
    }

    return cnt;
}

int check(){
    int cnt = 0, ans = 1e9;

    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            cnt = Find(i, j);

            for(int k=j+1;k<n;k++){
                int sum = 0;
                sum = Find(i, k) + Find(j, k);
                ans = min(ans, cnt + sum);
            }
        }
    }

    return ans;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> t;

    while(t--){
        cin >> n;

        for(int i=0;i<n;i++) cin >> s[i];

        if(n >= 33) cout << "0" << "\n";

        else cout << check() << "\n";
    }

    return 0;
}
