#include <bits/stdc++.h>

using namespace std;
/*
    cin 쓰고 싶을때
    fastio;
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
*/

int n, c;
int black[5005];
int vt[100000005];

int calc(int i, int j){
    int b = black[i] + black[j];
    int need = c - b;

    if(need == black[i] || need == black[j]) return 0;

    if(b == c){
        printf("1");
        return 1;
    }

    else if(b < c && vt[need]){
        printf("1");
        return 1;
    }

    return 0;
}

void black_Friday(){
    if(vt[c]){
        printf("1");
        return;
	}

    for(int i=1;i<n;i++) {
        for(int j=i+1;j<=n;j++){
            if(calc(i, j)) return;
        }
    }

    printf("0");
}

void input(){
    scanf("%d %d", &n, &c);

	for(int i=1;i<=n;i++) {
		scanf("%d", &black[i]);
		vt[black[i]] = 1;
	}
}

int main()
{
    input();

    black_Friday();

    return 0;
}
