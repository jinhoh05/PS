#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, l, u, i, hap;

pair<int, int> w[200005];

vector<int> v;

void calc(int x){
    printf("%d\n", x);
    for(int i=0; i<=x; i++){
        printf("%d ", w[i].second);
    }
}

int main()
{
    scanf("%d %d %d", &n, &l, &u);

    for(int i=0; i<n; i++){
        scanf("%d", &w[i].first);
        w[i].second = i;
    }

    sort(w, w + n);

    ll sum1=0, sum2=0, i, j;
    for(i=n-1; i>=0; i--){
        sum1 += w[i].first;

        v.push_back(w[i].second);

        if(sum1 >= l && sum1 <= u){
            printf("%d\n", n-i);
            for(j=i; j<n; j++)
            {
                printf("%d ", w[j].second);
                hap += w[i].first;
            }
            //cout << hap;
            return 0;
        }

        if(sum1 > u) break;
    }

    for(j=0; j<n-i; j++){
        sum2 += w[j].first;

        if(sum2 >= l && sum2 <= u){
            calc(j + 1);
            return 0;
        }
    }

    if(sum2 <= u){
        for(int k=0; k<=j; k++){
            sum1 = sum1 - w[n-k-1].first + w[k].first;
            v[k] = w[k].second;

            if(sum1 >= l && sum1 <= u){
                printf("%d\n", v.size());
                for(int i:v){
                    printf("%d ", i);
                }
                return 0;
            }
        }
    }

    printf("0");

    return 0;
}
