#include <bits/stdc++.h>

using namespace std;

int n, s, a;

vector<int> v;

int main() 
{    
    scanf("%d %d", &n, &s);
    
    for(int i=0; i<n; i++){
        scanf("%d", &a);
        v.push_back(a);
    }
    
    for(int i=0; i<n; i++){
        v[i] = abs(s-v[i]);
    }
    
    sort(v.begin(), v.end());
    
    a = gcd(v[0], v[1]);
    
    for(int i=2; i<n; i++){
        a = gcd(a, v[i]);
    }
    
    printf("%d", a);
}