#include <bits/stdc++.h>

using namespace std;
int n,mmo;
char s[10][10];
int used[10];
int num,mx;
int A[10];

int check(char a[],char b[]){
    int la=strlen(a),lb=strlen(b),i;
    for(i=min(la,lb);i>=1;i--){
        if(strncmp(a+la-i,b,i) == 0) break;
    }
    return i;
}

void permut(int lev,int sum){
    if(lev > n){
        if(sum > mx) mx=sum;
        return;
    }

    for(int i=1;i<=n;i++){
         if(used[i] == 0){
            A[lev]=i;
            used[i]=1;

            permut(lev+1,sum+check(s[A[lev-1]],s[i]));

            A[lev]=0;
            used[i]=0;
         }
    }
}

int main()
{
    scanf("%d",&n);
    int cnt=0;

    for(int i=1;i<=n;i++){
        scanf("%s",s[i]);
        cnt+=strlen(s[i]);
    }

    permut(1,0);

    printf("%d",cnt-mx);

    return 0;
}