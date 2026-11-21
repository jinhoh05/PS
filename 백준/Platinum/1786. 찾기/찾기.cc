#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000005;
char t[MAX], p[MAX];
int ans[MAX], pi[MAX], len_t, len_p, cnt;

void make_pi(){
    int j = 0;

    for(int i=1;i<len_p;i++){
        while(j > 0 && p[i] != p[j]) j = pi[j - 1];
        if(p[i] == p[j]) pi[i] = ++j;
    }
}

void do_KMP(){
    int j = 0;

    for(int i=0;i<len_t;i++){
        while(t[i] != p[j] && j > 0) j = pi[j - 1];
        if(t[i] == p[j]) j++;
        if(j == len_p - 1) ans[cnt++] = i - len_p + 3;
    }
}

int main()
{
    fgets(t, MAX, stdin);
    fgets(p, MAX, stdin);

    len_t = strlen(t), len_p = strlen(p);

    make_pi();

    do_KMP();

    printf("%d\n", cnt);
    for(int i=0;i<cnt;i++) printf("%d ", ans[i]);
}
