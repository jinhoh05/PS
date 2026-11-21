#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int N;

    cin >> N;

    for(int i = 1; i <= N * 2; i++)
    {
        for(int j = 1; j <= N * 5; j++)
        {
            if(j <= N || j >= (N * 5) - N + 1) printf("@");
            else printf(" ");
        }
        printf("\n");
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N * 5; j++) printf("@");
        printf("\n");
    }
    
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N * 5; j++)
        {
            if(j <= N || j >= (N * 5) - N + 1) printf("@");
            else printf(" ");
        }
        printf("\n");
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N * 5; j++) printf("@");
        printf("\n");
    }

    return 0;
}
