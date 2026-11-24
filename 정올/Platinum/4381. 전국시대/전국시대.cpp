#include <bits/stdc++.h>

using namespace std;
int n, m, t, num1, num2;
int l,i,r,s,j,e;
int bit[300005];

void update(int x, int val){
    for(;x<=n;x+=(x&-x)) bit[x] += val;
}

int query(int x){
    int sum = 0;
    for(;x;x-=(x&-x)) sum += bit[x];
    return sum;
}

void calc(){
    int a1 = query(i) - query(i - 1), a2 = query(j) - query(j - 1);
    int b1 = a1, b2 = a2;

    if(num1 < num2){
        b2 += (b1 + 1) / 2;
        b1 = b1 / 2;
    }

    else if(num1 > num2){
        b1 += (b2 + 1) / 2;
        b2 = b2 / 2;
    }

    else return;

    update(i, b1 - a1);
    update(j, b2 - a2);
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int k=1;k<=n;k++){
        scanf("%d",&t);
        update(k, t);
    }

    for(int k=1;k<=m;k++){
        scanf("%d %d %d",&l,&i,&r);
        scanf("%d %d %d",&s,&j,&e);

        num1 = query(r) - query(l - 1);
        num2 = query(e) - query(s - 1);

        calc();
    }

    for(int i=1;i<=n;i++) printf("%d ", query(i) - query(i - 1));

    return 0;
}