#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
/*
    cin 쓰고 싶을때
    fastio;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
*/

/// 최대길이 1 << 10 == 1024

char l[15], k[15];
int st, fin;
int bit[15], vt[(1 << 10) + 1];

queue<pii> q;

void change(pii t){
    int i, f = t.first, s = t.second;

    for(i=10;i>=0 && bit[i]>f;i--){}

    for(int j=i-1;j>=0;j--){
        int bit_num = (f ^ bit[j]);

        if(!vt[bit_num]){
            vt[bit_num] = 1;
            q.push({bit_num, s + 1});
        }
    }
}

void push(pii t){
    int f = t.first, s = t.second;

    if(f - 1 >= 0 && !vt[t.first - 1]){
        vt[f - 1] = 1;
        q.push({f - 1, s + 1});
    }

    if(f + 1 < 1024 && !vt[f + 1]){
        vt[f + 1] = 1;
        q.push({f + 1, s + 1});
    }
}

void bfs(){
    vt[st] = 1;
    q.push({st, 0});

	while(!q.empty()){
		pii t = q.front();
		q.pop();

		if(t.first == fin){
            printf("%d", t.second);
            return;
        }

		push(t);
        change(t);
	}
}

void input(){
    scanf(" %s", l);

	int bit_num = 1;
	for(int i=strlen(l)-1;i>=0;i--){
        st += (l[i] - '0') * bit_num;
        bit_num <<= 1;
	}

	scanf(" %s", k);

	bit_num = 1;
	for(int i=strlen(k)-1;i>=0;i--){
        fin += (k[i] - '0') * bit_num;
        bit_num <<= 1;
	}
}

int main()
{
	for(int i=0;i<12;i++) bit[i + 1] = (1 << i);

    input();

	bfs();

	return 0;
}
