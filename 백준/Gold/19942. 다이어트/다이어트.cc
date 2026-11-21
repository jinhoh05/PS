#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d, e = 1e9;
int A[20], B[20], C[20], D[20], E[20];
int x[20], z, f[20];

bool check[20];

void diet(int a1, int b1, int c1, int d1, int e1, int y, int k)
{
	if(e1 > e) return;

	if(a1 >= a && b1 >= b && c1 >= c && d1 >= d && e1 < e)
	{
		z = y;
		e = e1;

		for(int j = 0; j < y; j++) f[j]=x[j];

		return;
	}

	for(int i = k; i < n; i++)
	{
		if(check[i] == false)
		{
			check[i] = true;
			a1 = a1 + A[i];
			b1 = b1 + B[i];
			c1 = c1 + C[i];
			d1 = d1 + D[i];
			e1 = e1 + E[i];

			x[y] = i + 1;

			diet(a1, b1, c1, d1, e1, y + 1, i);

			check[i] = false;
			a1 = a1 - A[i];
			b1 = b1 - B[i];
			c1 = c1 - C[i];
			d1 = d1 - D[i];
			e1 = e1 - E[i];
		}
	}
}

int X, Y, Z, O;

void input()
{
    scanf("%d",&n);
	scanf("%d %d %d %d",&a,&b,&c,&d);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d %d", &A[i], &B[i], &C[i], &D[i], &E[i]);

		X = X + A[i];
		Y = Y + B[i];
		Z = Z + C[i];
		O = O + D[i];
	}
}

int main()
{
    input();

	if(X < a || Y < b || Z < c || O < d) printf("-1");

	else
    {
        diet(0, 0, 0, 0, 0, 0, 0);

        printf("%d\n",e);

        for(int i = 0; i < z; i++) printf("%d ", f[i]);
	}

	return 0;
}
