#include <bits/stdc++.h>

using namespace std;
int n, ans;
int problem[1005];

struct data{
    int date, score;
    bool operator<(const data &t)const{
        return score > t.score;
    }
}arr[1005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d", &arr[i].date, &arr[i].score);

    sort(arr + 1, arr + n + 1);

    for(int i=1;i<=n;i++){
        int idx = arr[i].date;

        if(!problem[idx]) problem[idx] = arr[i].score;

        else{
            while(problem[--idx]);
            if(idx != 0) problem[idx] = arr[i].score;
        }
    }

    for(int i=1;i<=1001;i++) ans += problem[i];
    printf("%d",ans);

    return 0;
}
