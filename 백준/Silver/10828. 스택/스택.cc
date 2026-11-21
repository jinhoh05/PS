#include <bits/stdc++.h>

using namespace std;
int n, num;
string a[5] = {"push", "top", "size", "pop"};
string s;
stack<int> stk;

void check(){
    if(s.compare(a[0]) == 0){
        scanf("%d",&num);
        stk.push(num);
    }

    else if(s.compare(a[1]) == 0){
        if(stk.empty()) printf("-1\n");
        else printf("%d\n", stk.top());
    }

    else if(s.compare(a[2]) == 0) printf("%d\n", stk.size());

    else if(s.compare(a[3]) == 0){
        if(stk.empty()) printf("-1\n");
        else{
            printf("%d\n", stk.top());
            stk.pop();
        }
    }

    else{
        if(stk.empty()) printf("1\n");
        else printf("0\n");
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin >> s;
        check();
    }

    return 0;
}
