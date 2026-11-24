#include <bits/stdc++.h>
using namespace std;

int x,y,z;
int arr[300];

int main() {
    //freopen("input.txt","r",stdin);

    scanf("%d %d %d",&x,&y,&z);

    if(x == y && y == z) printf("%d",10000+x*1000);


    else if(x == y || x == z || y == z){
        if(x == y || x == z) printf("%d",1000+x*100);
        else printf("%d",1000+y*100);
    }

    else{
        int big=max({x,y,z});
        printf("%d",big*100);
    }

}