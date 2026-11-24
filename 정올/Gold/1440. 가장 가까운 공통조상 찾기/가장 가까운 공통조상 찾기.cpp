#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> graph[10001];
bool vt[10001];

void track(int s){
    vt[s]=1;
    for(int v:graph[s]){
        track(v);
    }
    return;
}

void compare(int e){
    for(int v:graph[e]){
        if(vt[e] == 1){
            printf("%d",e);
            return;
        }
        else compare(v);
    }

    if(vt[e]) printf("%d",e);


    return;
}

int main()
{
    int s,e;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        graph[e].push_back(s);
    }

    scanf("%d %d",&s,&e);


    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }

    track(s);
    compare(e);

    return 0;
}
/*
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
13 5
*/