#include <bits/stdc++.h>

using namespace std;
int n,c,m,truck[10005];

struct data{

    int st,fin,box;

}box[10005];

bool comp(const data& a,const data& b){

    if(a.fin == b.fin) return a.st < b.st;
    return a.fin < b.fin;

}

int main()
{

    scanf("%d %d",&n,&c);
    scanf("%d",&m);

    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&box[i].st,&box[i].fin,&box[i].box);
    }

    sort(box+1,box+m+1,comp);


    int sum=0,ans=0;
    int mx=0;

    for(int i=1;i<=m;i++){
        sum=0;
        mx=box[i].box;
        for(int j=box[i].st;j<box[i].fin;j++){
            if(truck[j] > sum) sum=truck[j];
        }

        if(mx + sum > c) sum = c - sum;
        else sum=mx;
        ans+=sum;

        for(int k=box[i].st;k<box[i].fin;k++){
            truck[k]+=sum;
        }
    }

    printf("%d",ans);
    return 0;
}