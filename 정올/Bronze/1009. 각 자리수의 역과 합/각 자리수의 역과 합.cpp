#include <iostream>
#include <stdio.h>
using namespace std;
int s[11];
int main()
{
    int n;
    int a=0,b=0,c,d;
    int cnt=0;
    int sum=1;

    for(int i=0;i<10;i++){

        scanf("%d",&n);

        if(n == 0){
            return 0;
        }

        for(int j=0;;j++){
            s[j] = n % 10;
            n = n / 10;
            cnt++;
            if(n < 10){
                s[j+1]=n;
                break;
            }
        }

        for(int k=cnt;k>=0;k--){
            a+=s[k] * sum;
            sum=sum*10;
            b+=s[k];
        }
        printf("%d %d\n",a,b);
        a=b=0;
        sum=1;
        cnt=0;
    }


    return 0;
}