#include <bits/stdc++.h>

using namespace std;

int n, cnt, sum;

struct time{
    int st, fin;

    bool operator<(const time &t)const{
        if(fin == t.fin) return st < t.st;
        return fin < t.fin;
    }
}confer[100005];

void conference(){
    sum = cnt = 1;

    for(int i=2;i<=n;i++){
        if(confer[i].st >= confer[sum].fin){
            cnt++;
            sum = i;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=1;i<=n;i++) cin >> confer[i].st >> confer[i].fin;

    sort(confer + 1, confer + n + 1);

    conference();

    cout << cnt;

    return 0;
}
