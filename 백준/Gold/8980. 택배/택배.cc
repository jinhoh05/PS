#include <bits/stdc++.h>

using namespace std;

int n, c, m, ans;
int truck[10005];

struct Data{
    int st, fin, box;

    bool operator<(const Data &t)const{
        if(fin == t.fin) return st < t.st;
        return fin < t.fin;
    }

}box[10005];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> c >> m;

    for(int i=1;i<=m;i++){
        cin >> box[i].st >> box[i].fin >> box[i].box;
    }

    sort(box + 1, box + m + 1);

    for(int i=1;i<=m;i++){
        int sum = 0;
        int mx = box[i].box;

        for(int j=box[i].st;j<box[i].fin;j++){
            if(truck[j] > sum) sum = truck[j];
        }

        if(mx + sum > c) sum = c - sum;
        else sum = mx;

        ans += sum;

        for(int k=box[i].st;k<box[i].fin;k++) truck[k] += sum;
    }

    cout << ans;

    return 0;
}
