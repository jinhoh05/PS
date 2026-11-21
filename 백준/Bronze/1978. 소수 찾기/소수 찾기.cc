#include <bits/stdc++.h>;

using namespace std;
int n, cnt;
int prime[1005];

void eratos(){
     prime[1]=1;

     for(int i=2;i*i<=1000;i++){
         if(prime[i] == 0){
             for(int j=i*i;j<=1000;j+=i) prime[j] = 1;
         }
     }
 }

int main()
{
     scanf("%d", &n);

     eratos();

     for(int i=1;i<=n;i++){
         int a;
         scanf("%d", &a);
         prime[a] ?  : cnt++;
     }

     printf("%d",cnt);

     return 0;
 }
