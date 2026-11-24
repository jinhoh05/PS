#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000;

int n;
int DP[505][505];
int dist[505], spring[505], hold[505];

int bitonic(int a, int b)
{
    if(a == n - 1 || b == n - 1){
        return a == n - 1 && dist[a] <= dist[a] + spring[a] && hold[a] && dist[a] - spring[a] <= dist[b];
    }
   
    int &ret = DP[a][b];
   
    if(ret != -1) return ret;
    
    int st = min(n - 1, max(a, b) + 1);
    
    ret = 0;
    
    for(int i = st; i < n; i++){
        if(dist[i] <= dist[a] + spring[a]){
            ret = (ret + bitonic(i, b)) % MOD;
        }
        
        if(hold[i] && dist[i] - spring[i] <= dist[b]){
            ret = (ret + bitonic(a, i)) % MOD;
        }
    }
    
    return ret;
}

void input()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", dist + i, spring + i, hold + i);
    }
}

int main()
{
    input();
 
    memset(DP, -1, sizeof(DP));
    
    printf("%d", bitonic(0, 0));
    
    return 0;
}