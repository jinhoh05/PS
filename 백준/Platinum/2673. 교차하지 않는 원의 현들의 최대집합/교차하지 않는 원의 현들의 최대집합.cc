#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

int N;
int DP[105][105], c[105][105]; 

void dynamic()
{
  for(int i = 1; i <= 100; i++)
    for(int j = i; j >= 1; j--)
      for(int k = j; k < i; k++)
        DP[j][i] = max(DP[j][i], DP[j][k] + DP[k][i] + c[i][j]);
}

void input()
{
  scanf("%d", &N);

  for(int i = 1; i <= N; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    c[a][b] = c[b][a] = 1;
  }
}

int main()
{
  input();

  dynamic();

  printf("%d", DP[1][100]);

  return 0;
}