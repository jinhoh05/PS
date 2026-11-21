#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long int n,m,a[510],b[510],ans[510];
long long qwe,asd,mid,t;
long long check(long long  max)
{
    long long i,num=0,pos=0;
    memset(b,0,sizeof(b));
    for (i=n; i>=1; i--)
    {
        if (pos+a[i]<=max&&i>=m-num)
            pos=pos+a[i];
        else
        {
            ++num;
            pos=a[i];
            b[i]=1;
        }
    }

    if (num+1==m)
    {
        for (i=1; i<=n; i++)
            ans[i]=b[i];
        return 1;
    }
    else
        return 0;
}
int main()
{
    long long i;
    scanf("%lld",&t);
    while (t--)
    {
        qwe=0;
        asd=0;
        scanf("%lld%lld",&n,&m);
        for (i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            asd+=a[i];
            if (a[i]>qwe)
                qwe=a[i];
        }
        memset(ans,0,sizeof(ans));
        while (qwe<=asd)
        {
            mid=(qwe+asd)/2;
            if (check(mid)==1)
                asd=mid-1;
            else
                qwe=mid+1;
        }
        for (i=1; i<n; i++)
            if (ans[i]==1)
                printf("%lld / ",a[i]);
            else
                printf("%lld ",a[i]);
        printf("%lld\n",a[n]);
    }
    return 0;
}