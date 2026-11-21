#include <bits/stdc++.h>
   
using namespace std;
long long n,m;
int len;
   
long long int small(){
    long long a=n,res;
    int zero=0,change=0,cnt=0;
   
    for(int k=0;k<=len;k++){
        res=(a >> k) & 1;
        if(res == 1 && zero == 1){
            a = a ^ (1ll << k);
            a = a ^ (1ll << k-1);
            change=k-2;
            if(k==len) cnt--;
            break;
        }
        else if(res == 0) zero=1;
        else{
            zero=0;
            cnt++;
        }
    }
   
    if(zero == 0 || res == 0) return 0;
    else if(change <= 0) return a;
   
    for(int i=change;i>change-cnt;i--){
        a = a | (1ll << i);
    }
    change-=cnt;
   
    for(int i=change;i>=0;i--){
        a = a & (~(1ll << i));
    }
   
    return a;
}
   
long long int big(){
    long long a=n,res;
    int one=0,change=0,cnt=0;
   
    for(int k=0;k<=len;k++){
        res=(a >> k) & 1;
        if(res == 0 && one == 1){
            a = a ^ (1ll << k);
            a = a ^ (1ll << k-1);
            change=k-2;
            break;
        }
        else if(res == 0) one=0;
        else{
            one=1;
            cnt++;
        }
    }
   
    cnt-=1;
    if(res == 1 || one == 0) return 0;
    else if(change <= 0) return a;
   
    for(int i=change;i>change-cnt;i--){
        a = a & (~(1ll << i));
    }
   
    for(int i=0;i<cnt;i++){
        a = a | (1ll << i);
    }
   
    return a;
}
   
int main()
{
    cin >> n;
   
    m=n;
    while(m>0){
        len++;
        m/=2;
    }
   
    printf("%lld %lld",small(),big());
   
    return 0;
}