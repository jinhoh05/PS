#include <bits/stdc++.h>

using namespace std;
const int LM = 1<<19;
int n,bit[LM];
int arr[LM];
map<int, int> dic;

void update(int k, int w = 1){
    for(;k>0;k-=k&-k) bit[k]+=w;
}

int query(int k, int sum = 0){
    for(;k<LM;k+=k&-k) sum+=bit[k];
    return sum;
}

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        dic[arr[i]] = i;
    }
    int k=1;
    for(auto& d:dic){
        arr[d.second]=k++;
    }
    for(int i=1;i<=n;i++){
        update(arr[i]);
        printf("%d\n",query(arr[i]));
    }

    return 0;
}