#include<cstdio>
#include<cstring>
using namespace std;

int n, t, len;
int cnt[30], word[30], vt[30], node[30][30];
char s[105][15];

void push_init(){
    printf("\n");

    len = 0;

    for(int i=0;i<30;i++) cnt[i] = word[i] = vt[i] = 0;

    memset(s, 0, sizeof(s));
    memset(node, 0, sizeof(node));
}

void output(){
    if(len < 0) printf("?");

    if(len == 0) printf("!");

    else{
        for(int i=0;i<len;i++) printf("%c", char('a' + word[i]));
    }
}

void find_word(){
    if(len < 0){
        printf("!");
        return;
    }

    while(1){
        int u = 0, l = 0;

        for(int i=0;i<26;i++){
            if(vt[i] && !cnt[i]){
                u = i;
                l++;
            }
        }

        if(l > 1) len = -1;

        if(l != 1) break;

        vt[u] = 0;
        word[len++] = u;

        for(int i=0;i<26;i++){
            if(node[u][i]) cnt[i]--;
        }
    }

    output();
}

int check(int i, int j, int k){
    if(k >= strlen(s[j])){
        len = -1;
        return 0;
    }

    int u = s[i][k] - 'a', v = s[j][k] - 'a';

    if(u == v) return 1;

    if(!node[u][v]){
        node[u][v] = 1;
        cnt[v]++;

        if(node[v][u]) len = -1;
    }

    return 0;
}

void find_node(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=0;k<strlen(s[i]);k++){
                if(check(i, j, k)) continue;
                else break;
            }
        }
    }
}

void input(){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf(" %s", s[i]);
        for(int j=0;j<strlen(s[i]);j++) vt[s[i][j] - 'a'] = 1;
    }
}

int main()
{
    scanf("%d", &t);

    for(int i=1;i<=t;i++){
        input();

        find_node();

        find_word();

        push_init();

    }

    return 0;
}