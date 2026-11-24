#include <bits/stdc++.h>

using namespace std;
int n,k,ans=1,l;
int a[11],b[11],ans_a,ans_b;

void check(int i){
    printf("%d %d\n",ans_a,ans_b);

    while(ans_a == ans_b){
        i--;
        if(i==0) break;
        if(a[i] > b[i]) ans_a++;
        else if(b[i] > a[i]) ans_b++;
    }

    if(ans_a > ans_b) printf("A");
    else if(ans_a < ans_b) printf("B");
    else printf("D");
}

int main()
{
    for(int i=1;i<=10;i++) scanf("%d",&a[i]);
    for(int i=1;i<=10;i++) scanf("%d",&b[i]);

    for(int i=1;i<=10;i++){
        if(a[i] > b[i]) ans_a+=3;
        else if(b[i] > a[i]) ans_b+=3;
        else{
            ans_a++;
            ans_b++;
        }

        if(i==10){
            check(10);
            return 0;
        }
    }

    return 0;
}