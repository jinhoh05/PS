#include <iostream>

using namespace std;

int n, k, ans;
int coin[15];

int main()
{
    scanf("%d %d", &n, &k);

	for(int i=1;i<=n;i++) scanf("%d", &coin[i]);

	for(int i=n;i>=1;i--){
		ans += k / coin[i];
		k %= coin[i];
	}

	printf("%d", ans);

    return 0;
}
