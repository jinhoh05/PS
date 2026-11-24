#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int prime(int x)
{
    int divisor=(int)sqrt(x);
    for(int i=2;i<=divisor;i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    int m;
    int cnt=0,sum=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&m);
        if (m < 2) printf("2");

        else{
            for(int j=m;j>1;j--){
                if(prime(j)==1){
                    cnt=j;
                    break;
                }
            }

            for(int f=cnt+1;;f++){
                if(prime(f)==1){
                    sum=f;
                    break;
                }
            }

            if(m - cnt > sum - m) printf("%d",sum);
            else if(m - cnt < sum - m) printf("%d",cnt);
            else printf("%d %d",cnt, sum);
        }
             printf("\n");
    }
    return 0;
}