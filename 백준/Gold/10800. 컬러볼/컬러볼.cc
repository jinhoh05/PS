#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int n, hap;
int color[MAX], com[MAX];

struct st{
    int c, s, idx;

    bool operator<(const st &t)const{
        return s < t.s;
    }

}ball[MAX];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> ball[i].c >> ball[i].s;
        ball[i].idx = i;
    }

    sort(ball, ball + n);

    for(int i = 0, j = 0; i < n; i++){
        for(; ball[i].s > ball[j].s; j++){
            hap += ball[j].s;
            color[ball[j].c] += ball[j].s;
        }

        com[ball[i].idx] = hap - color[ball[i].c];
    }

    for(int i = 0; i < n; i++) cout << com[i] << "\n";

    return 0;
}
