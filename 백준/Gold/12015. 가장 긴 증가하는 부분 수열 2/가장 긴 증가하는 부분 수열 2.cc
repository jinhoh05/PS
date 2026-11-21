#include <bits/stdc++.h>

using namespace std;

int n, a, cnt;
vector<int> v;

int main()
{    
    v.push_back(INT_MIN);

    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        scanf("%d", &a);
        if(a > v.back()){
            v.push_back(a);
            cnt++;
        }

        else{
            vector<int>::iterator temp = lower_bound(v.begin(), v.end(), a);
            *temp = a;
        }
    }

    printf("%d", cnt);

    return 0;
}
