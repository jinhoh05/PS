#include <bits/stdc++.h>
using namespace std;

int findnum(int a[], int st, int target){
    for(int i=st;i<10;i++){
        if(a[i] == target){
            return i;
        }
    }
    return 0;
}

int straight(int a[]){
    for(int i=1;i<5;i++){
        if(a[i] != a[i-1]+1){
            return 0;
        }
    }
    return 1;
}


int main(){

    char s[6];
    int a[10]={0};
    int b[6];
    int ans=0,t,u;


    for(int i=0;i<5;i++){
        scanf(" %c %d",&s[i], &b[i]);
        a[b[i]]+=1;
    }

    sort(s,s+5);
    sort(b,b+5);

    if(s[0] == s[4]){
        if(straight(b)) ans=900+b[4];
        else ans=600+b[4];
    }
    else if(t=findnum(a,1,4)){
        ans=800+t;
    }
    else if((t=findnum(a,1,3)) && (u=findnum(a,1,2))){
        ans=t*10 + u + 700;
    }
    else if(straight(b)) ans=500+b[4];

    else if(t=findnum(a,1,3)) ans=400+t;

    else if(t=findnum(a,1,2)){
        u=findnum(a,t+1,2);
        if(u==0){
            ans=200+t;
        }
        else{
            if(t > u) ans=t*10+300+u;
            else ans=u*10+300+t;
        }
    }
    else ans=100+b[4];

   // for(int i=0;i<5;i++){
     //   printf(" %c %d\n", s[i],b[i]);
    //}
    printf("%d",ans);

    return 0;
}