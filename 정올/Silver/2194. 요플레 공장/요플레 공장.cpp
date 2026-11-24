#include <bits/stdc++.h>

using namespace std;
int n,s;

struct data{

    int c,y;

}a[10005];

int main(){

    scanf("%d %d",&n,&s);

    long long int cnt=0;

    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].c,&a[i].y);
    }

    int sum=a[1].c;


    for(int i=1;i<=n;i++){
        if(sum + s < a[i].c){
            cnt+=(sum + s) * a[i].y;
            sum+=s;
        }
        else {
            cnt+=a[i].c * a[i].y;
            sum=a[i].c;
        }
    }

    printf("%lld",cnt);

    return 0;
}
/*
10 25

84 125
134 45
92 86
1 127
24 195
38 163
5 54
69 49
14 117
77 199
*/