#include <bits/stdc++.h>

using namespace std;

int K, N;
int ans[40];

char s[100005];

vector<int> v;

int find_num(char c)
{
    if(c <= '9') return c - '0';
    return c - 'A'+ 10;
}

int calc(char *s, int b)
{
    int val = 0;

    for(int i = 0; i < strlen(s); i++)
    {
        val = val * b + find_num(s[i]);
    }

    return val;
}

int main()
{
    scanf("%d %d ", &K, &N);

    fgets(s, 100005, stdin);
    strtok(s, "\r\n");

    char *P = strtok(s, " ");

    while(P)
    {
        switch(*P)
        {
            case '+' : v.push_back(-4); break;
            case '-' : v.push_back(-3); break;
            case '*' : v.push_back(-2); break;
            case 'x' : v.push_back(-1); break;
            default : v.push_back(calc(P, K) % K); break;
        }

        P = strtok(NULL, " ");
    }

    for(int j = 0; j < K; j++)
    {
        stack<int> stk;

        for(int i = 0; i < v.size(); i++)
        {
            int t = 0;

            switch(v[i])
            {
                case -4 : t = stk.top(); stk.pop(); stk.top() = (stk.top() + t) % K; break;
                case -3 : t = stk.top(); stk.pop(); stk.top() = (stk.top() - t + K) % K; break;
                case -2 : t = stk.top(); stk.pop(); stk.top() = (stk.top() * t) % K; break;
                case -1 : stk.push(j); break;
                default :  stk.push(v[i]); break;
            }
        }

        ans[j] = stk.top();
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%s", s);
        char c = ans[calc(s, K) % K] % K;
        printf("%c\n", c <= 9 ? c + '0' : c - 10 + 'A');
    }

    return 0;
}