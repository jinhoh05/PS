#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int S;
int X, Y, A;
int L, B, R, T;

int tree[3000][3000];

void update(int x, int y, int val)
{
    for(int i = x; i <= S; i += (i & -i))
        for(int j = y; j <= S; j += (j & -j))
            tree[i][j] += val;
}

ll query(int x, int y)
{
    ll sum = 0;

    for(int i = x; i ; i -= (i & -i))
        for(int j = y; j ; j -= (j & -j))
            sum += tree[i][j];

    return sum;
}

int main()
{
    while(t != 3)
    {
        scanf("%d", &t);

        if(t == 0)
        {
            scanf("%d", &S);
        }

        else if(t == 1)
        {
            scanf("%d %d %d", &X, &Y, &A);

            X++;
            Y++;

            swap(X, Y);

            update(X, Y, A);
        }

        else if(t == 2)
        {
            scanf("%d %d %d %d", &L, &B, &R, &T);

            L++;
            B++;
            R++;
            T++;

            swap(L, B);
            swap(R, T);

            printf("%lld\n", query(R, T) - query(R, B - 1) - query(L - 1, T) + query(L - 1, B - 1));
        }
    }


    return 0;
}
