#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;

struct Data{

    int num, loc;

    bool operator<(const Data &t)const{
        return num < t.num;
    }

}arr[100005];

vector<int> v;

int main(){

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i].num);
        arr[i].loc = i;
    }

    sort(arr, arr+n);

    int a=arr[0].loc;
    for(int i=1; i<n; i++){
        if(arr[i].loc < a) ans++;
        a=arr[i].loc;
    }

    printf("%d", ans);

    return 0;
}
