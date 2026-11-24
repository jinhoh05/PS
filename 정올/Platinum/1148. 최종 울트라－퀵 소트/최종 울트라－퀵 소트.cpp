#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int n, t;
ll cnt;

struct data{
	int x, lev;
	bool operator<(const data &t)const{
		return x > t.x;
	}
}a[500005];
int bit[500005];

void update(int x, int val){
	for(;x<=n;x+=(x&-x)) bit[x] += val;
}

ll query(int x){
	ll sum = 0;
	for(;x;x-=(x&-x)) sum += bit[x];
	return sum;
}

void sorting(){
	sort(a + 1, a + n + 1);

	for(int i=1;i<=n;i++){
		cnt += query(a[i].lev - 1);
		update(a[i].lev, 1);
	}

	printf("%lld", cnt);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		a[i] = {t, i};
	}

	sorting();

    return 0;
}