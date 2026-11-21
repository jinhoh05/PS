#include <cstdio>

using namespace std;

int get_gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {

    int a, b, gcd, lcm;

    scanf("%d %d", &a, &b);

    gcd = get_gcd(a, b);

    printf("%d\n%d", gcd, a * b / gcd);

    return 0;
}
