/*#include <bits/stdc++.h>

using namespace std;
int n, cnt, a, b, c;

int main()
{
    scanf("%d",&n);

    for(int a=1;a<n;a++){
        for(int b=a;b<n;b++){
            int c = n-(a+b);
            if(c < b) break;
            if(b + a > c) cnt++;
        }
    }

    printf("%d",cnt);

    return 0;
}*/

#include <iostream>

using namespace std;
using ll = long long;

int n, cnt = 1, sum = 1;
ll triangle[2000005];

int main()
{
    triangle[3] = triangle[5] = 1;

    for(int i = 6; i <= 2000000; i++)
    {
        if(i % 2 == 0) triangle[i] = triangle[i - 3];

        else
        {
            if(cnt == 7)
            {
                cnt = 1;
                sum++;
            }

            triangle[i] = triangle[i - 2] + sum;

            if(i % 12 == 3) triangle[i]++;

            cnt++;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &n);
        printf("%lld\n", triangle[n]);
    }

    return 0;
}