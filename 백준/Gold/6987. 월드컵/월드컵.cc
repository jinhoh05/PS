#include <bits/stdc++.h>

using namespace std;

int cnt;
int win[10], draw[10], lose[10];
int r_win[10], r_draw[10], r_lose[10];

int dfs(int a, int b){
    if(b > 6){
        if(win[a] != r_win[a] || draw[a] != r_draw[a] || lose[a] != r_lose[a]) return 0;
        a++;
        b = a + 1;
    }

    if(a == 6) return (win[a] == r_win[a] && draw[a] == r_draw[a] && lose[a] == r_lose[a]);

    r_win[a]++, r_lose[b]++;
    if(dfs(a, b + 1)) return 1;
    r_win[a]--, r_lose[b]--;

    r_draw[a]++, r_draw[b]++;
    if(dfs(a, b + 1)) return 1;
    r_draw[a]--, r_draw[b]--;

    r_win[b]++, r_lose[a]++;
    if(dfs(a, b + 1)) return 1;
    r_win[b]--, r_lose[a]--;

    return 0;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=4;i++){
        memset(r_win, 0, sizeof(r_win));
        memset(r_draw, 0, sizeof(r_draw));
        memset(r_lose, 0, sizeof(r_lose));

        for(int j=1;j<=6;j++) cin >> win[j] >> draw[j] >> lose[j];

        if(dfs(1, 2)) cout << "1 ";
        else cout << "0 ";
    }

    return 0;
}
