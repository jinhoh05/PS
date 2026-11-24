#include <bits/stdc++.h>

using namespace std;

const int LM=100005;
int N,Q,k;

struct data{
    int id,freq;
    char str[15];
}A[LM];

bool comp(data a,data b){
    if(a.freq != b.freq){
        return a.freq > b.freq;
    }

    if(strcmp(a.str,b.str)){
        return strcmp(a.str,b.str)<0;
    }

    return a.id < b.id;
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d %d",&N,&Q);

    for(int i=1;i<=N;++i){
        scanf("%s %d",A[i].str,&A[i].freq);
        A[i].id=i;
    }

    sort(A+1,A+N+1,comp);

    for(int i=1;i<=Q;i++){
        scanf("%d",&k);
        printf("%d ",A[k].id);
    }

    return 0;
}