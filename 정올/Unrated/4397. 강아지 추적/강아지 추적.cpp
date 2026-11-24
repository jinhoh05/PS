#include <iostream>

using namespace std;
long long int k,t,d;
long long int hap_x,hap_y;
int dx[10005],dy[10005];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%lld %lld",&k,&t);
    for(int i=1;i<=k;i++){
        scanf("%lld %lld",&dx[i],&dy[i]);
        hap_x+=dx[i];
        hap_y+=dy[i];
    }

    if(t==0){
        printf("0 0");
        return 0;
    }
    
    d=t/k;
    hap_x*=d;
    hap_y*=d;

    for(int i=1;i<=t%k;i++){
        hap_x+=dx[i];
        hap_y+=dy[i];
    }

    printf("%lld %lld",hap_x,hap_y);

    return 0;
}