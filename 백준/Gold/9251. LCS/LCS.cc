#include <bits/stdc++.h>

using namespace std;

char s1[1005], s2[1005];
int i, j, DP[1005][1005];

void dynamic(){
    for(i=1;s1[i];i++){
        for(j=1;s2[j];j++){
            DP[i][j] = max({DP[i][j - 1], DP[i - 1][j], DP[i - 1][j - 1] + (s1[i] == s2[j])});
        }
    }
}

int main()
{
    scanf("%s %s", s1 + 1, s2 + 1);

    dynamic();

    printf("%d", DP[i - 1][j - 1]);
    
    return 0;
}

