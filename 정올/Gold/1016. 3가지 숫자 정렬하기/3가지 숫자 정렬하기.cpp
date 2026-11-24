#include <bits/stdc++.h>

using namespace std;
int n,ans;
int arr[1005],num[4];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        num[arr[i]]++;
    }
    num[2]+=num[1];
    num[3]+=num[2];

    int l=1,ch=0;
    for(int i=1;i<=n;i++){
        ch=0;
        if(i > num[l]) l++;
        if(i <= num[l] && arr[i] != l){
            for(int j=num[arr[i]];j>num[l];j--){
                if(arr[j] == l){
                    swap(arr[i], arr[j]);
                    ch=1;
                    ans++;
                    break;
                }
            }
            if(ch == 0){
                for(int j=n;j>=1;j--){
                    if(arr[j] == l){
                        swap(arr[i], arr[j]);
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    printf("%d",ans);

    return 0;
}
/*
20
1 1 3 2 1 1 1 3 2 1 3 3 2 1 3 1 1 2 3 1
*/