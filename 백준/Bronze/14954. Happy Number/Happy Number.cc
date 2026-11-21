#include <bits/stdc++.h>

using namespace std;

int n, t;

set<int> st;

int main()
{
    
    scanf("%d", &n);

    while(n > 1)
    {
        if(st.count(n))
        {
            printf("UNHAPPY\n");
            return 0;
        }

        st.insert(n);

        int next = 0;

        for(int x = n; x; x /= 10) next += (x % 10) * (x % 10);

        n = next;
    }

    printf("HAPPY\n");
    

    return 0;
}
