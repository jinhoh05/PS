#include <bits/stdc++.h>

using namespace std;

void input(int N, int M, vector<int> &A, vector<int> &B)
{
    int x;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        A.push_back(x);
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &x);
        B.push_back(x);
    }

    sort(B.begin(), B.end());
}

int main()
{
    for(int i = 0; i < 4; i++)
    {
        int N, M;
        vector<int> A, B;
        bool flag = false;

        input(N, M, A, B);

        for(int k : A)
        {
            int val = 10000 - k;
            auto p = lower_bound(B.begin(), B.end(), val);

            if(p != B.end() && *p == val)
            {
                flag = true;
                break;
            }
        }

        if(flag) printf("YES");
        else printf("NO");
        printf("\n");
    }

    return 0;
}
