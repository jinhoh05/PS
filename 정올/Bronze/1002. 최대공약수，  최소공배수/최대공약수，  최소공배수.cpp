#include <iostream>

using namespace std;
int gcd_get(int x, int y){
    if(y == 0) return x;
        return gcd_get(y, x % y);
}

int main()
{
    int n;
    int a[11];
    int gcd,lcm;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    gcd = lcm = a[0];

    for (int i=1; i < n; i++) {
        gcd = gcd_get(gcd, a[i]);
        lcm = lcm / gcd_get(lcm, a[i]) * a[i];
    }
    printf("%d %d",gcd, lcm);
    return 0;
}