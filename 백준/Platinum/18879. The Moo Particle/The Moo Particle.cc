#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 4;

int n, cnt;
int nx, ny;
int mn = 1e9, mx = -1e9;
int x[MAX], y[MAX], id[MAX];
int mnx[MAX], mxy[MAX];

bool comp(int a, int b)
{
    if(x[a] == x[b]) return y[a] > y[b];
    else return x[a] < x[b];
}

void calc()
{
	for(int i = 1; i <= n; i++)
    {
		if(mn > mxy[i] && mx < mnx[i]) cnt++;

		mn = min(mn, y[id[i]]);
		mx = max(mx, x[id[i]]);
	}
}

void particle()
{
    int cx, cy;

    for(int i = n - 1; i > 0; i--)
    {
		cy = y[id[i]];
		mxy[i] = max(mxy[i + 1], cy);
    }

	mnx[n] = x[id[n]];

	for(int i = n - 1; i > 0; i--)
	{
		cx = x[id[i]];
		mnx[i] = min(mnx[i + 1], cx);
	}
}

void input()
{
    scanf("%d", &n);

	for(int i = 1; i <= n; i++)
    {
		scanf("%d %d", &x[i], &y[i]);
		id[i] = i;
	}

	sort(id + 1, id + n + 1, comp);

	mxy[n] = y[id[n]];
}

int main()
{
    input();

	particle();

	calc();

	printf("%d", cnt);

	return 0;
}
