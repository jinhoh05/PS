#include <bits/stdc++.h>

using namespace std;
int n, cnt;
int vt[200];
char s[105][105];

void check(int i){
    for(int j=0;j<strlen(s[i]);j++){
        if(s[i][j] != s[i][j - 1] && vt[s[i][j]] == 1) return;
        else vt[s[i][j]] = 1;
    }
    cnt++;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s", s[i]);
        check(i);
        memset(vt, 0, sizeof(vt));
    }

    printf("%d",cnt);
    return 0;
}
