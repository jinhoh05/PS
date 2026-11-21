#include <bits/stdc++.h>

using namespace std;
using ll = long long; 
 
int n, x, ans;
int chess[10];

int main()
{
    chess[1] = chess[2] = 1;
    chess[3] = chess[4] = chess[5] = 2;
    chess[6] = 8;
    
	for(int i = 1; i <= 6; i++)
	{
	    scanf("%d", &x);
	    printf("%d ", chess[i] - x);
	}
	
	return 0;
}