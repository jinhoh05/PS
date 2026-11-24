#include <bits/stdc++.h>

using namespace std;
int n,fish[200005],cnt,hap;

int check(){
    int f_hap=fish[1];
    for(int i=2;i<=n+cnt;i++){
        if(f_hap < fish[i]){
            cnt++;
            fish[n+cnt]=f_hap;
            return 0;
        }
        f_hap+=fish[i];
    }
    return 1;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&fish[i]);
    }

    while(1){
        sort(fish+1,fish+n+1+cnt);
        if(check()){
            printf("%d",cnt);
            return 0;
        }
    }


    return 0;
}