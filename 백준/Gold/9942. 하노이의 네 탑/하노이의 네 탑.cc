#include <stdio.h>
#include <limits.h>
#define MAXN 1001
 
int N;
long long pow2[MAXN], T[MAXN];
long long move(int n, int r){
    if(n==1) return 1;  
     
    long long m = -1;
    for(int k=1;k<n;++k){        
        if(n-k >= 63) continue;
        long long kVal = (T[k]==0) ? T[k]=move(k,r) : T[k];     
        long long nkVal = pow2[n-k]-1;
        long long x = 2 * kVal + nkVal;
        if(m==-1 || x<m) m=x;
    }
    return m;
}
 
int main(){
    pow2[0]=1;
    for(int i=1;i<MAXN;++i) pow2[i] = pow2[i-1]<<1;    
     
    int test=0;
    while(~scanf("%d",&N)){
        printf("Case %d: %lld\n",++test,move(N,4)); 
    }   
    return 0;
}