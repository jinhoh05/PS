#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;
int t;

vector<int> v;

int check(string s){
    stack<char> stk;
    int ans=0, sc=1;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            sc*=2;
            stk.push('(');
        }

        else if(s[i] == '['){
            sc*=3;
            stk.push('[');
        }

        else if(s[i] == ')'){
            if(stk.empty() || stk.top() != '('){
                ans=0;
                break;
            }
            if(s[i-1] == '('){
                ans+=sc;
                sc/=2;
                stk.pop();
            }
            else{
                sc/=2;
                stk.pop();
            }
        }

        else if(s[i] == ']'){
            if(stk.empty() || stk.top() != '['){
                ans=0;
                break;
            }
            if(s[i-1] == '['){
                ans+=sc;
                sc/=3;
                stk.pop();
            }
            else{
                sc/=3;
                stk.pop();
            }
        }
    }

    if(!stk.empty()) ans=0;

    return ans;
}

int main(){
    cin.tie(0)->ios_base::sync_with_stdio(false);
    /*
    scanf("%d", &t);

    while(t--){
        string s1, s2;
        cin >> s1 >> s2;

        int a = check(s1);
        int b = check(s2);

        if(a > b) printf(">");
        else if(a < b) printf("<");
        else printf("=");
    }*/

    string s;
    cin >> s;
    cout << check(s);

    return 0;
}
