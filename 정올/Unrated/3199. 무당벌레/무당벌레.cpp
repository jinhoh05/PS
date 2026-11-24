#include <bits/stdc++.h>

using namespace std;
int g,n;
string b;

void check(){
    int cnt=0,change=0,not_=0,vt[105];

    for(int i=65;i<=90;i++) vt[i]=0;

    for(int i=0;i<n;i++){
        if(b[i]=='_') change++;
    }

    if(change==0){
        for(int i=0;i<n;i++){
            if(b[i-1] != b[i]) not_++;
            else not_=0;
            if(not_==2||i==n-1 && not_==1){
                printf("NO");
                return;
            }
        }
        printf("YES");
        return;
    }

    else{
        for(int i=0;i<n;i++){
            if(b[i]!='_') vt[b[i]]++;
        }
        for(int i=65;i<=90;i++){
            if(vt[i]==1){
                printf("NO");
                return;
            }
        }
        printf("YES");
        return;
    }
}

int main()
{
    scanf("%d",&g);
    for(int i=1;i<=g;i++){
        scanf("%d",&n);
        cin >> b;
        check();
        printf("\n");
    }

    return 0;
}