#include <bits/stdc++.h>

using namespace std;

int A, B, P, Q;
int bottle[100005][5];

struct st{
    int a, b;
};

queue<st> q;

int &water(int a, int b){
    if(!a) return bottle[b][0];
    if(a == A) return bottle[b][1];
    if(!b) return bottle[a][2];
    if(b == B) return bottle[a][3];
    return bottle[0][2];
}

void push(int a, int b, int d){
    if(water(a, b) < 2e9) return;
    water(a, b) = d;
    q.push({a, b});
}

void bfs(){
    push(0, 0, 0);

    while(!q.empty()){
        st t = q.front();
        q.pop();

        int a = t.a, b = t.b, d = water(a, b);

        push(0, b, d + 1);
        push(a, 0, d + 1);
        push(A, b, d + 1);
        push(a, B, d + 1);

        int val = min(A - a, b);
        push(a + val, b - val, d + 1);

        val = min(a, B - b);
        push(a - val, b + val, d + 1);
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> A >> B >> P >> Q;

    for(int i=0;i<=B;i++){
        for(int j=0;j<4;j++){
            bottle[i][j] = 2e9;
        }
    }

    bfs();

    if(water(P, Q) < 2e9) cout << water(P, Q);
    else cout << -1;

    return 0;
}
