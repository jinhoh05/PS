#include <bits/stdc++.h>

using namespace std;

int n, m;
int board[2001];
int palin[2001][2001];
vector<int> v;

int Palindrome(int s, int e) {
	if(s >= e) return 1;

	int &ret = palin[s][e];

	if(ret != -1) return ret;

	if(board[s] == board[e]) return ret = Palindrome(s + 1, e - 1);

	else return 0;
}

void input(){
    memset(palin, -1, sizeof(palin));

	scanf("%d", &n);

	for(int i=1;i<=n;i++) scanf("%d", &board[i]);

	scanf("%d", &m);
}

int main()
{
    input();

    for(int i=1;i<=m;i++){
        int s, e;
		scanf("%d %d", &s, &e);
		v.push_back(Palindrome(s, e));
	}

	for(int u : v) printf("%d\n", u);
}
