#include <bits/stdc++.h>;

using namespace std;
int s, e;
int prime[1000005];

void eratos(int n){
     prime[1]=1;

     for(int i=2;i*i<=n;i++){
         if(prime[i] == 0){
             for(int j=i*i;j<=n;j+=i) prime[j] = 1;
         }
     }
 }

int main()
{
     scanf("%d %d", &s, &e);

     eratos(e);

     for(int i=s;i<=e;i++){
         if(prime[i]==0) printf("%d\n",i);
     }

     return 0;
 }
