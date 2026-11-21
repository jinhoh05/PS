#include <bits/stdc++.h>

using namespace std;

int n, ans;
int card[1005][10];
int score[1005];

vector<int> v;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin >> card[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            for(int k=j+1;k<=5;k++){
                for(int h=k+1;h<=5;h++){
                    score[i] = max(score[i], (card[i][j] + card[i][k] + card[i][h]) % 10);
                }
            }
        }
        ans = max(ans, score[i]);
    }

    int ans_num;

    for(int i=1;i<=n;i++){
        if(score[i] == ans) ans_num = i;
    }

    cout << ans_num;

    return 0;
}
