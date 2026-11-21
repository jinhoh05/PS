#include <bits/stdc++.h>
using namespace std;
int cnt=0;
int sum=-1;
int n;
char a[500010];

int cmp(){
    int redl=0;
    int bluel=0;
    int redr=0;
    int bluer=0;
    int d;
    int ans=0;
    int rcnt=0;
    int bcnt=0;

    if(a[0] == 'R'){
        for(int i=0;i<n;i++){
            if(a[i] != 'R') break;
            redl++;
        }
    }

    else if(a[0] == 'B'){
        for(int i=0;i<n;i++){
            if(a[i] != 'B') break;
            bluel++;
        }
    }

    if(a[n-1] == 'R'){
        for(int i=n-1;i>=0;i--){
            if(a[i] != 'R') break;
            redr++;
        }
    }

    else if(a[n-1] == 'B'){
        for(int i=n-1;i>=0;i--){
            if(a[i] != 'B') break;
            bluer++;
        }
    }

    for(int i=0;i<n;i++){
        if(a[i]=='R') rcnt++;
        if(a[i]=='B') bcnt++;
    }

    ans=rcnt-redl;
    if(ans>bcnt-bluer) ans = bcnt - bluer;
    if(ans>rcnt-redr) ans=rcnt - redr;
    if(ans>bcnt-bluel) ans = bcnt - bluel;

    return ans;
}

int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf(" %c",&a[i]);
    }

    printf("%d",cmp());

    return 0;
}