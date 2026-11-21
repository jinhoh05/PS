#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
priority_queue<int> MAX, MIN;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];

    for(int i=0;i<n;i++){
        if(MAX.size() > MIN.size()) MIN.push(-a[i]);
        else MAX.push(a[i]);

        if(!MAX.empty() && !MIN.empty()){
            if(MAX.top() > -MIN.top()){
                int MAX_val = MAX.top();
                int MIN_val = -MIN.top();

                MAX.pop(), MIN.pop();

                MAX.push(MIN_val);
                MIN.push(-MAX_val);
            }
        }
        cout << MAX.top() << "\n";
    }

    return 0;
}
