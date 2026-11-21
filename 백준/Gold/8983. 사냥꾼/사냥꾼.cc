#include <bits/stdc++.h>

using namespace std;

int n, m, l, ans;
int shot_p[100005];

struct st{
    int x, y;

    bool operator<(const st &t)const{
        if(x == t.x) return y < t.y;
        return x < t.x;
    }

}animal[100005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n >> l;

    for(int i=1;i<=m;i++) cin >> shot_p[i];

    for(int i=1;i<=n;i++) cin >> animal[i].x >> animal[i].y;

    sort(shot_p + 1, shot_p + m + 1);

    sort(animal + 1, animal + n + 1);

    int j = 1;

    for(int i=1;i<=n;i++){
        while(j <= m && shot_p[j] < animal[i].x) j++;

        int shot = shot_p[j], x = animal[i].x, y = animal[i].y;

        if(j > 1 && abs(shot_p[j - 1] - x) + y <= l) ans++;
        else if(j <= m && abs(shot - animal[i].x) + y <= l) ans++;
    }

    cout << ans;

    return 0;
}
