#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,e;
int n,sum;
int num[5]={1,2,4,8,16};

int check(int i){
    if(i == 4){
        if(sum > e){
            sum=e;
        }
    }
    else if(i == 3){
        if(sum > d){
            sum=d;
        }
    }
    else if(i == 2){
        if(sum > c){
            sum=c;
        }
    }
    else if(i == 1){
        if(sum > b){
            sum=b;
        }
    }
    else if(i == 0){
        if(sum > a){
            sum=a;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    scanf("%d",&n);
    int cnt=0;
    int i=4;

    while(n > 0){
        sum=0;
        if(n >= num[i]){
           sum=n/num[i];
           check(i);

           if(sum != 0){
              n=n-(sum*num[i]);
              cnt+=sum;
           }
        }

        if(i == 0 && n > 0){
            printf("impossible");
            return 0;
        }

        i--;
    }

    printf("%d",cnt);

    return 0;
}