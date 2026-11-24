#include <bits/stdc++.h>

using namespace std;
int n,ans=1;
using ll=long long;
const int LM=100005;
struct data{

    int st,ed;
    bool operator<(const data&r)const{
        return st < r.st;
    }

}A[LM];

int main()
{

    int i,j,st,sm,sd,em,ed;
    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&sm,&sd,&em,&ed);
        A[i]={sm*100 + sd,em*100+ed};
    }

    sort(A,A+n);

    st=301,ed=301;
    for(i=0;i<n;i++){
        if(A[i].ed <= ed) continue;
        if(A[i].st > ed) break;
        if(A[i].st > st){
            ans++;
            st=ed;
        }
        ed=A[i].ed;
        if(ed > 1130) break;
    }

    if(ed < 1201) ans=0;
    printf("%d",ans);

    return 0;
}