#include <iostream>

using namespace std;
using ll = long long;

const ll MAX = ll(1e9) + 7;

int n, q, l, r;
ll F[1000005], N[1000005];

void fibo(){
    N[l] = (N[l] + F[1]) % MAX;
    N[l + 1] = (N[l + 1] + F[2] - F[1]) % MAX;
    N[r + 1] = (N[r + 1] + MAX - F[r - l + 2]) % MAX;
    N[r + 2] = (N[r + 2] + MAX - F[r - l + 1]) % MAX;
}

void input(){
    scanf("%d %d", &n, &q);

	for(int i=2;i<=n+1;i++){
		F[i] = (F[i - 1] + F[i - 2]) % MAX;
	}

	for(int i=1;i<=q;i++){
        scanf("%d %d", &l, &r);
        fibo();
	}
}

int main() {

    F[1] = 1;

    input();

	for(int i=2;i<=n;i++){
		N[i] = (N[i] + N[i - 1] + N[i - 2]) % MAX;
	}

	for(int i=1;i<=n;i++){
		printf("%d ", N[i]);
	}

    return 0;
}
