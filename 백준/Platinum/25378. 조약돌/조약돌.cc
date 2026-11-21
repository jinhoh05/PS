#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, p, l, ans, cnt;
int rock[2505];

vector<int> v[2505];

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &rock[i]);
        v[i].push_back(rock[i]);
    }
    
    ans = n;

    for(int i=1; i<n; i++){
        for(int j : v[i-1]){
            if(j < rock[i]){
                v[i].push_back(rock[i] - j);
            }
            
            else if(j == rock[i]){
                v[i].erase(v[i].begin(), v[i].end());
                ans--;
                break;
            }
        }
    }

    printf("%d", ans);

    return 0;
}