#include <bits/stdc++.h>

using namespace std;

int n, x;
queue<int> q;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    while(n--){
        string s;
        cin >> s;

        if(s == "push"){
            cin >> x;
            q.push(x);
        }

        else if(s == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }

            else cout << -1 << "\n";
        }

        else if(s == "size") cout << q.size() << "\n";


        else if(s == "empty") cout << q.empty() << "\n";

        else if(s == "front"){
            if(!q.empty()) cout << q.front() << "\n";

            else cout << -1 << "\n";
        }

        else if(s == "back"){
            if(!q.empty()) cout << q.back() << "\n";

            else cout << -1 << "\n";
        }
    }

    return 0;
}
