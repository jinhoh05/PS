#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int N;
int Next[2505][2505];

int64_t a, b, c;
int64_t DP[2505][2505];

string S;

vector<int> find_start(char *s)
{
    int len = strlen(s), head = 0, start = 0;

    vector<int> v(len);

    for(int i = 1; i < len; i++)
    {
        if(v[i - start] >= head - i)
        {
            head = max(head, i);

            while(head < len && s[head] == s[head - i]) head++;

            v[i] = head - i;
            start = i;
        }

        else v[i] = min(len - i, v[i - start]);
    }

    return v;
}

void init()
{
    for(int i = 0; i < N; i++)
    {
        int len = 0;
	auto v = find_start(&S[i]);

	for(int j = i + 1; j < N; j++)
        {
            int now_len = min(j - i, v[j - i]);
	    while(len < now_len) Next[i][i + ++len] = j;
	}

	while(len < N - i) Next[i][i + ++len] = N;
    }
}

void dynamic()
{
    for(auto &i : DP)
        for(auto &j : i)
            j = 1e18;

    for(int i = 0; i < N; i++) DP[i][i + 1] = a + b;

    for(int k = 1; k < N; k++)
    {
    	for(int l = 0; l + k <= N; l++)
	{
	    int r = l + k, now = l, cnt = 1;

	    if(l) DP[l - 1][r] = min(DP[l - 1][r], DP[l][r] + a);
	    if(r + 1 <= N) DP[l][r + 1] = min(DP[l][r + 1], DP[l][r] + a);

            while(Next[now][now + k] < N)
            {
		now = Next[now][now + k];
		cnt++;
		DP[l][now + k] = min(DP[l][now + k], DP[l][r] + (c * cnt) + (a * (now + k - l - (k * cnt))) + b);
	    }
	}
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> N >> S;
    cin >> a >> b >> c;

    init();

    dynamic();

    printf("%"PRId64, DP[0][N] - b);

    return 0;
}
