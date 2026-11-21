#include <bits/stdc++.h>

using namespace std;
long long int s, e, ans, a, num, A;

int main() {

	scanf("%lld %lld", &s, &e);

	a = 2;
    ans = e - s + 1;
    vector<bool> v(ans, false);

	while(a * a <= e){
		A = a * a;
		num = s / A;

		if(s % A != 0) num += 1;

        while(num * A <= e){
			if(v[num * A - s] == false){
				v[num * A - s] = true;
				ans -= 1;
			}
			num += 1;
		}

		a += 1;
	}

	printf("%lld", ans);

	return 0;
}
