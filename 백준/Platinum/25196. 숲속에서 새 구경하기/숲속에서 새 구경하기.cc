#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll val;
ll A, Ast, Aend, B, Bst, Bend, C, Cst, Cend;

int main()
{
    scanf("%d %d %d", &A, &Ast, &Aend);
    scanf("%d %d %d", &B, &Bst, &Bend);
    scanf("%d %d %d", &C, &Cst, &Cend);

	val = A * B * C + 1;

	while(Aend < val && Bend < val && Cend < val){
		ll l = max(Ast, max(Bst, Cst)), r = min(Aend, min(Bend, Cend));

		if(l > r){
			if(Aend <= Bend && Aend <= Cend) Ast += A, Aend += A;
			else if(Bend <= Aend && Bend <= Cend) Bst += B, Bend += B;
			else Cst += C, Cend += C;
		}

		else{
            printf("%lld", l);
			return 0;
		}
	}

	printf("-1");

	return 0;
}
