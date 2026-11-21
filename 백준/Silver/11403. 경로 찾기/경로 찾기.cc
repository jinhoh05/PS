#include <bits/stdc++.h>

using namespace std;

int n;
int graph[105][105];
int vt[105];

void dfs(int x){
    for(int i=0;i<n;i++){
        if(graph[x][i] == 1 && !vt[i]){
            vt[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> graph[i][j];

    for(int i=0;i<n;i++){
        memset(vt, 0, sizeof(vt));
        dfs(i);

        for(int j=0;j<n;j++)
            if(vt[j]) graph[i][j] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
