#include <bits/stdc++.h>

using namespace std;

#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define _Rep(i,a,b) for(int i=a;i>=b;i--)
#define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

const int N=5005;
const int Zero=1e6;
const double eps=1e-7;

template <typename T> void read(T &x)
{
    x=0; 
    int f=1; 
    char c=getchar(); 
    
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1; 
    
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+c-'0'; x*=f;
}

#define int long long

int n,q;
int a[N];
int f[N][N];
int cnt[Zero*2+5];

signed main()
{ 
    read(n),read(q); 
    
    Rep(i,1,n) read(a[i]),a[i]+=Zero; 
    Rep(i,1,n)
    { 
        Rep(j,i+1,n)
        { 
            if(a[i]+a[j]<=3*Zero&&a[i]+a[j]>=Zero) f[i][j]=cnt[Zero*3-a[i]-a[j]]; 
            cnt[a[j]]++; 
        }
        
        Rep(j,i+1,n)cnt[a[j]]--; 
    } 
    
    Rep(i,1,n) Rep(j,1,n) f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1]; 
    
    while(q--)
    { 
        int l,r; 
        read(l),read(r); 
        printf("%lld\n",f[r][r]-f[l-1][r]-f[r][l-1]+f[l-1][l-1]); 
  
    }
    
    return 0;
}