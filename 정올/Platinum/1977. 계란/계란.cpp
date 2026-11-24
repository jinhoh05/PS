#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int K, cnt_min = 1e9;
int arr[4];

pii egg[4];

vector<vector<int>> ans, path;

int sorting(int x, int y, int z)
{
    if(egg[x].first < 0 || egg[y].first < 0) return 0;
    
    egg[x].first--; egg[y].first--;
    egg[z].first += 2;
    
    vector<int> tmp(4);
    
    for(int i = 0; i < 4; i++) tmp[egg[i].second] = egg[i].first;
    
    ans.push_back(tmp);
    
    sort(egg, egg + 3);

    return 1;
}

int calc(int x)
{
    int cnt = 0;
    ans.clear();
    
    for(int i = 0; i < 4; i++) egg[i] = {arr[i], i};
    
    swap(egg[x], egg[3]);
    
    sort(egg, egg + 3);
    
    int &a0 = egg[0].first, &a1 = egg[1].first, &a2 = egg[2].first, &a3 = egg[3].first;
    
    if((a0 + a1 + a2) % 2) cnt += sorting(2, 3, 1);
    
    while(a0 + a1 < a2)
    {
        if(cnt > K) return 1e9;
        
        if(a1 == 0) cnt += sorting(2, 3, 1);
        
        else cnt += sorting(1, 2, 0);
        
        if((a0 + a1 + a2) % 2) cnt += sorting(2, 3, 1);
    }
    
    while(a0 + a1 + a2)
    {
        if(cnt > K) return 1e9;
        
        cnt += sorting(1, 2, 3);
    }
    
    return cnt;    
}

void output()
{
    for(int i = 0; i < 4; i++) printf("%d ", arr[i]);
    printf("\n");

    for(auto i : path)
    {
        for(auto j : i) cout << j << ' ';
        cout << "\n";
    }
}

int main()
{   
    scanf("%d", &K);
    
    for(int i = 0; i < 4; i++) scanf("%d", &arr[i]);
    
    for(int i = 0; i < 4; i++)
    {
       int val = calc(i);
       
       if(cnt_min > val)
       {
           cnt_min = val;
           path = ans;
       }
    }

    output();

    return 0;
}