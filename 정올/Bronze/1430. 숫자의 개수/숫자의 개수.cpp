#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n[10]={0};
    int m;
    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    m = a*b*c;

    while(m >= 10){
        if(m % 10 == 0){
            n[0]++;
        }

        if(m % 10 == 1){
            n[1]++;
        }

        if(m % 10 == 2){
            n[2]++;
        }

        if(m % 10 == 3){
            n[3]++;
        }

        if(m % 10 == 4){
            n[4]++;
        }

        if(m % 10 == 5){
            n[5]++;
        }

        if(m % 10 == 6){
            n[6]++;
        }

        if(m % 10 == 7){
            n[7]++;
        }

        if(m % 10 == 8){
            n[8]++;
        }

        if(m % 10 == 9){
            n[9]++;
        }

        m=m/10;
    }

    n[m]++;

    for(int i=0;i<10;i++){
        printf("%d\n",n[i]);
    }

    return 0;
}