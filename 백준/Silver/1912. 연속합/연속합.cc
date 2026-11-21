#include <bits/stdc++.h>

using namespace std;
int n, a;
int sum = -1e9, hap = -1e9, num;

int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);

        hap += num;
        if(hap < num) hap = num;
        if(hap > sum) sum = hap;
    }

    printf("%d", sum);

    return 0;
}
