#include <bits/stdc++.h>

using namespace std;

int n, ans;
int cnt[25][25];

char safe[25][25];

int check(int i, int j){
    int grip=0;
    for(int k=1; k<=n; k++){
        if(safe[i][k] == 'V') grip++;
        if(safe[k][j] == 'V') grip++;
    }

    if(safe[i][j] == 'V') grip--;

    return grip;
}

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            scanf(" %c", &safe[i][j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cnt[i][j] = check(i, j);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cnt[i][j] % 2 == 1) ans++;
        }
    }

    printf("%d", ans);

    return 0;
}
