#include <bits/stdc++.h>

using namespace std;

int n, k, cnt;

char s[20005];

int main()
{
    scanf("%d %d", &n, &k);
    scanf("%s", s);

    for(int i = 0; i < n; i++)
    {
        if(s[i] != 'P') continue;

        for(int j = i - k; j <= i + k; j++){
            if(0 <= j && j < n && s[j] == 'H')
            {
                s[j]='-';
                cnt++;
                break;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}
