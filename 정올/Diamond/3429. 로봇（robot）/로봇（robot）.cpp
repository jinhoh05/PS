#include <bits/stdc++.h>

using namespace std;

int N, R, M;
int robot[1000005];
int dist[2000005];

int main()
{
    scanf("%d", &N);
    scanf("%d %d", &R, &M);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &robot[i]);
    }

    sort(robot, robot + N);

    robot[N] = robot[0] + M;

    for(int i = 0; i < N; i++)
    {
        dist[i] = robot[i + 1] - robot[i] - (R * 2);
        dist[i + N] = dist[i];
    }

    int sum = 0, ans = 0;

    for(int i = 0; i < 2 * N - 1; i++)
    {
        sum += dist[i];
        if(sum < 0) sum = 0;

        if(ans < sum) ans = sum;
    }

    printf("%d", (ans + 1) / 2);

    return 0;
}