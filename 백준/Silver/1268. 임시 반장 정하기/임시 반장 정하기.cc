#include <bits/stdc++.h>

using namespace std;

int n;
int vt[1005];
int stu[1005][5];

pair<int, int> ans;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin >> stu[i][j];
        }
    }

    ans.second = 1;
    int cnt = 0;

    for(int i=1;i<=n;i++){
        memset(vt, 0, sizeof(vt));
        vt[i] = 1;
        cnt = 0;

        for(int j=1;j<=5;j++){
            for(int k=1;k<=n;k++){
                if(vt[k]) continue;

                if(stu[i][j] == stu[k][j]){
                    vt[k] = 1;
                    cnt++;
                }
            }
        }

        if(ans.first < cnt) ans = make_pair(cnt, i);
    }

    cout << ans.second;

    return 0;
}
