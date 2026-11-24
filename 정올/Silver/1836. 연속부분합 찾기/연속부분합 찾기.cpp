#include <bits/stdc++.h>

using namespace std;
long long int hap,sum=-1e9;
int n,a;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        hap+=a;
        if(hap < a) hap=a;
        if(hap > sum) sum=hap;
    }

    printf("%d",sum);

}