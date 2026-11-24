#include <bits/stdc++.h>

using namespace std;
int n;

struct data{

    int st,fin;

}a[105];

bool comp(const data& a,const data& b){
    return a.st < b.st;
}

int main(){

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].st,&a[i].fin);
    }

    sort(a+1,a+n+1,comp);

    int sum=1,cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i].st > a[sum].fin){
            cnt++;
            sum=i;
        }
        if(a[i].fin < a[sum].fin) sum=i;
    }

    printf("%d",cnt);



    return 0;
}