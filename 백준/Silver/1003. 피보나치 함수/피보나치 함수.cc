#include <cstdio>
using namespace std;

int n, fibo;
int DP[45];

int main() {

    DP[1] = DP[2] = 1;

    for(int i=3;i<=40;i++) DP[i] = DP[i-1] + DP[i-2];

    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        scanf("%d", &fibo);

        if(fibo == 0) printf("%d %d\n", 1, 0);
        else if(fibo == 1) printf("%d %d\n", 0, 1);
        else printf("%d %d\n", DP[fibo - 1], DP[fibo]);
    }

    return 0;
}
