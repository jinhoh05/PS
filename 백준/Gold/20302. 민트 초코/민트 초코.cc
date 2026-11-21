#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
int n, a, sum, pn;
int spf[MAX], pr[MAX], numer[MAX], demoni[MAX];
char c;

void prime(int x, int u){
    while(x > 1){
        if(u == 1) numer[spf[x]]++;
        else demoni[spf[x]]++;
        x /= spf[x];
    }
}

void Euler(){
    for(int i=2;i<=MAX;i++){
        if(!spf[i]) spf[i] = pr[pn++] = i;

        for(int j=0;i*pr[j]<MAX;j++) {
            spf[i * pr[j]] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}

int check(){
    if(numer[0] > 0) return 1;
    for(int i=2;i<=100000;i++){
        if(numer[i] < demoni[i]) return 0;
    }
    return 1;
}

int main()
{
    Euler();

    scanf("%d %d", &n, &a);
    
    if(a == 0) numer[0]++;
    
    prime(a, 1);

    for(int i=1;i<n;i++){
        scanf(" %c %d",&c, &a);
        a = abs(a);
      
        if(a == 0) numer[a]++;
      
        if(c == '*') prime(a, 1);
        else prime(a, 2);
    }

    if(!check()) printf("toothpaste");
    else printf("mint chocolate");

    return 0;
}
