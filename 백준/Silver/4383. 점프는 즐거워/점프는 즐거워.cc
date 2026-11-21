#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int arr[3005];

vector<int> v;

int main(){

    while(scanf("%d", &n) != EOF){
        set<int> s;

        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
        for(int i = 1; i < n; i++){
            int k = abs(arr[i] - arr[i-1]);
            if(0 < k && k < n) s.insert(k);
        }

        if(s.size() == n - 1) printf("Jolly\n");
        else printf("Not jolly\n");
    }

    return 0;
}
