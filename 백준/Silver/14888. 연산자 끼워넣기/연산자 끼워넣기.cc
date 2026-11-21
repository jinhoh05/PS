#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 5;

int n;
int num[15], op[5];
int MAX_NUM = -MAX, MIN_NUM = MAX;

void dfs(int Plus, int Minus, int multiply, int divide, int cnt, int sum){
    if(cnt == n){
         MAX_NUM = max(MAX_NUM, sum);
         MIN_NUM = min(MIN_NUM, sum);
    }

    if(Plus > 0) dfs(Plus - 1, Minus, multiply, divide, cnt + 1, sum + num[cnt]);

    if(Minus > 0) dfs(Plus, Minus - 1, multiply, divide, cnt + 1, sum - num[cnt]);

    if(multiply > 0) dfs(Plus, Minus, multiply - 1, divide, cnt + 1, sum * num[cnt]);

    if(divide > 0) dfs(Plus, Minus, multiply, divide - 1, cnt + 1, sum / num[cnt]);
}

int main()
{
    cin >> n;

    for(int i=0;i<n;i++) cin >> num[i];

    for(int i=0;i<4;i++) cin >> op[i];

    dfs(op[0], op[1], op[2], op[3], 1, num[0]);

    cout << MAX_NUM << "\n" << MIN_NUM;

    return 0;
}
