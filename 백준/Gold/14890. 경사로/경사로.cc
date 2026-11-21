#include <bits/stdc++.h>

using namespace std;

int n, l, ans, len;
int hill[205][105];

int check(int i, int j){
    if(hill[i][j] == hill[i][j + 1]) len++;
    else if(hill[i][j] + 1 == hill[i][j + 1] && len >= l) len = 1;
    else if(hill[i][j] - 1 == hill[i][j + 1] && len >= 0) len = -l + 1;
    else return 0;

    return 1;
}

void way(){
    int i, j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            hill[i + n][j] = hill[j][i];
        }
    }

    for(i=0;i<n*2;i++){
        len = 1;
        for(j=0;j<n-1;j++){
            if(!check(i, j)) break;
        }

        if(j == n - 1 && len >= 0) ans++;
    }
}

void input(){
    scanf("%d %d", &n, &l);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &hill[i][j]);
        }
    }
}

int main(){

    input();

    way();

    printf("%d", ans);

    return 0;
}
