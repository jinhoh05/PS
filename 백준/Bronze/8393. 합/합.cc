#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
 
int n, x, ans;
int chess[10];

int main()
{
    scanf("%d", &n);
    
	for(int i = 1; i <= n; i++)
	{
	    //scanf("%d", &x);
	    ans += i;
	}
	
	printf("%d", ans);
	
	return 0;
}