#include <bits/stdc++.h>

using namespace std;
int cnt[201],c;
char a[11];
int len,q;

void dfs(int lev,char eng){
    if(lev > len){
        q++;
        return;
    }

    for(int i='a';i<='z';i++){
        if(cnt[i] > 0 && eng != i){
            cnt[i]--;
            dfs(lev+1,i);
            cnt[i]++;
        }
    }
}

int main()
{
    char s[10];

    scanf("%s",s);

    len=strlen(s);

    for(int i=0;i<len;i++){
        cnt[s[i]]++;
    }

    dfs(1,'0');

    printf("%d",q);

    return 0;
}