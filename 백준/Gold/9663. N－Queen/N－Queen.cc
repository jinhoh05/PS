#include <bits/stdc++.h>

using namespace std;
int n, cnt;
int queen[15], l[30], r[30], chk[30];
int A[15], used[15];

void permut(int lev){
    if(lev > n){
        cnt++;
        return;
    }

    for(int i=1;i<=n;i++){
         if(used[i] == 0 && l[i + lev] == 0 && r[i - lev + 4] == 0){
            A[lev] = i;
            used[i] = 1;
            l[i + lev] = 1;
            r[i - lev + 4] = 1;

            permut(lev + 1);

            A[lev] = 0;
            used[i] = 0;
            l[i + lev] = 0;
            r[i - lev + 4] = 0;
         }
    }
}

int main()
{
    scanf("%d",&n);

    permut(1);

    printf("%d",cnt);

    return 0;
}
