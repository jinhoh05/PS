#include <iostream>
#include <set>
using namespace std;
int arr[21];
int N;
set<int> s;
void output(int idx, int sum)
{
    s.insert(sum);
    if (idx == N)
        return;
    output(idx + 1, sum + arr[idx]);
    output(idx + 1, sum);
}
int main()
{
    int M, result;
    M = result = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        M += arr[i];
    }
    output(0, 0);
    result = M - s.size() + 1;
    printf("%d\n", result);
}