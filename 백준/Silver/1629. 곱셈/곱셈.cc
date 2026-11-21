#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A, B, C;

ll f(ll y){
	if(y==1) return A%C;
	
	ll k = f(y/2)%C;
	
	if(y%2 == 0) return k*k%C;
	else return k*k%C*A%C;
}

int main(){
	scanf("%d %d %d",&A,&B,&C);
	printf("%lld\n",f(B));
	
	return 0;
}