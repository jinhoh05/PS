#include <bits/stdc++.h>

using namespace std;

const int ans = 123456789;

int puzzle;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<int> q;
map<int, int> vt;

void push(int t, string s, int z, int x, int y, int nx, int ny){
    if(0 <= nx && nx < 3 && 0 <= ny && ny < 3){
        swap(s[x * 3 + y], s[nx * 3 + ny]);

        int puz = stoi(s);

        if(!vt.count(puz)){
            vt[puz] = vt[t] + 1;
            q.push(puz);
        }
    }
}

void bfs(){
    q.push(puzzle);
    vt[puzzle] = 0;

    while(!q.empty()){
        int t = q.front();
        q.pop();

        string s = to_string(t);

        if(t == ans) break;

        int z = s.find('9');
        int x = z / 3;
        int y = z % 3;

        for(int i=0;i<4;i++) push(t, s, z, x, y, x + dx[i], y + dy[i]);
    }
}

void input(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int x;
            cin >> x;

            if(x == 0) x = 9;
            puzzle = puzzle * 10 + x;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    input();

    bfs();

    if(!vt.count(ans)) cout << -1;
    else cout << vt[ans];

    return 0;
}
