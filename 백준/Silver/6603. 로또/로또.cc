#include<bits/stdc++.h>

using namespace std;

int k;
int lotto[15], Set[15];

void dfs(int x, int depth){
    if(depth == 6){
        for(int i=0;i<6;i++) cout << Set[i] << " ";
        cout << '\n';
        return;
    }

    for(int i=x;i<k;i++){
        Set[depth] = lotto[i];
        dfs(i + 1, depth + 1);
    }
}

int main()
{
    while(1){
        cin >> k;

        if(!k) break;

        for(int i=0;i<k;i++) cin >> lotto[i];

        dfs(0, 0);

        cout << "\n";
    }

    return 0;
}
