#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int valid(ll n, ll k, ll m, ll x) 
{
  ll g = 0;
  
  while(k > 0 && g < n) {
    ll y = (n - g) / x;
    
    if(y < m) {
      ll lo = (n-g + m-1) / m;
      return lo <= k;
    }
    
    ll mo = n - x*y;
    ll day = (mo - g) / y + 1;
    
    if(day > k) day = k;
    
    g += y * day;
    k -= day;
  }
  
  return g >= n;
}
 
int main() 
{
  ll n, k, m;
  
  scanf("%lld %lld %lld", &n, &k, &m);
  
  ll lhs = 1;
  ll rhs = 1e12;
  
  while(lhs < rhs)
  {
    ll mid = (lhs + rhs + 1) / 2;
    
    if(valid(n, k, m, mid)) lhs = mid;
    
    else rhs = mid - 1;
  }
  
  printf("%lld\n", lhs);
}