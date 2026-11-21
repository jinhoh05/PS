#include <bits/stdc++.h>

using namespace std;

int height, width, k;
int ans = -1;
    
string arr[50];

int main()
{
    scanf("%d %d", &height, &width);

    for(int i = 0; i < height; i++)
        cin >> arr[i];
 
    scanf("%d", &k);

    for(int i = 0; i < height; i++)
    {
        int cnt = 0;
        
        for(int j = 0; j < width; j++)
        {
            if(arr[i][j] == '0') cnt++;
        }
        
        int sum = 0;
        
        if(cnt <= k && cnt % 2 == k % 2)
        {
            for(int j = 0; j < height; j++)
            {
                if(arr[i] == arr[j]) sum++;
            }
        }
        
        ans = max(sum, ans);
    }
    
    printf("%d", ans);
    
    return 0;
}