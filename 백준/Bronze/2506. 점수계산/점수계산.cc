#include <stdio.h>
int main()
{
    int i, n, n1, sum = 0, cnt = 0;

    scanf("%d", &n);

    for(i = 0; i < n; i++)    
    {
        scanf("%d", &n1);
        if (n1 == 1)
        {
            cnt++;
            sum += cnt;
        }
        
        else if (n1 == 0) cnt = 0;
    }
    
    printf("%d\n", sum);
}

