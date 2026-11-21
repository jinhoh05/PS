#include <bits/stdc++.h>

using namespace std;

int n;
int square[505][505];
int a[10];
int b[10];

int chamwae(){
    int sum=0;
    int sm=0;
    int code=0;

    for(int i=0;i<6;i++){
        sum=b[i];
        if(sum > sm){
            sm=sum;
            code=i;
        }
    }
    
    int cnt=0;
    if(code != 0){
        for(int i=6;i<=6+code;i++){
            b[i]=b[cnt];
            cnt++;
        }
    }

    sum=0;
    cnt=0;
    code++;
    while(cnt<2){
        sum+=b[code]*b[code+1];
        code=code+3;
        cnt++;
    }
    printf("%d",sum*n);
    return 0;
}

int main()
{
    scanf("%d",&n);

    for(int i=0;i<6;i++){
        scanf("%d %d",&a[i], &b[i]);
    }

    chamwae();

    return 0;
}