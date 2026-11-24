#include <bits/stdc++.h>

using namespace std;
int n, m;
int a[1000005], ans[1000005];

void res(){
    for(int i=1;i<=m;i++){
        a[i] = ans[i] = -1;
    }
}

int calc(){
    int t;
    set<int> s;

    for(int i=1;i<=m;i++){
        scanf("%d",&t);

        if(t==0){
            s.insert(i);
            ans[i]=0;
        }

        else{
            auto it=s.upper_bound(a[t]);

            if(it == s.end()){
                while(m > i){
                    m--;
                    scanf("%d",&t);
                }
                return 0;
            }

            ans[*it] = t;
            a[t] = i;
            s.erase(it);
        }
    }

    return 1;
}

int main()
{
    for(int i=1;i<=4;i++){
        scanf("%d %d", &n, &m);
        res();
        if(calc()){
            printf("YES\n");
            for(int j=1;j<=m;j++){
                if(ans[j] != -1) printf("%d ", ans[j]);
            }
            printf("\n");
        }
        else printf("NO\n");
    }

    return 0;
}