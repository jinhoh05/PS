#include <bits/stdc++.h>

using namespace std;
int n;
char a[100005];

int same2(int s,int e){
    while(s < e){
        if(a[s++] != a[e--]) return 0;
    }
    return 1;
}

int same(int s,int e){
    while(s < e){
        if(a[s] != a[e]){
            if(same2(s+1,e) || same2(s,e-1)) return 1;
            else return 2;
        }
        s++;
        e--;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);

    while(n!=0){
        scanf("%s",a);
        printf("%d\n",same(0,strlen(a)-1));
        n--;
    }

    return 0;
}