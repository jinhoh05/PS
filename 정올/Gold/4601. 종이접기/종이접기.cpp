#include <bits/stdc++.h>

using namespace std;

int k, h;
int l, r, s, e;
int p[4][2][2];

void calc()
{
    p[0][1][0] = p[1][0][0] = p[2][1][1] = p[3][0][1] = 1;
    p[0][0][1] = p[1][1][1] = p[2][0][0] = p[3][1][0] = 2;
    p[0][1][1] = p[1][0][1] = p[2][1][0] = p[3][0][0] = 3;
}

void input()
{
    scanf("%d ", &k);

    r = e = pow(2, k);

    for(int i = 0; i < 2 * k; i++)
    {
        char c;
        scanf(" %c", &c);

        if(c == 'D') s = (s + e) / 2;
        else if(c == 'U') e = (s + e) / 2;
        else if(c == 'R') l = (l + r) / 2;
        else if(c == 'L') r = (l + r) / 2;
    }

    scanf("%d", &h);
}

int main()
{
    input();

    calc();

    for(int i = 0; i < pow(2, k); i++)
    {
        for(int j = 0; j < pow(2, k); j++)
        {
            printf("%d%s", p[h][abs(l - j) % 2][abs(s - i) % 2], j == pow(2, k) - 1 ? "" : " ");
        }

        if(i == pow(2, k) - 1) break;

        printf("\n");
    }

    return 0;
}