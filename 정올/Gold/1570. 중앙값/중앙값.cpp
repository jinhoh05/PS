#include <bits/stdc++.h>

using namespace std;
int n,mid;
priority_queue<int> a,b;

void push(int x){
    if(x < mid) a.push(x);
    else b.push(-x);
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&mid);
    printf("%d\n",mid);

    int i,x,y;
    for(int i=0;i<n/2;i++){
        scanf("%d %d",&x,&y);
        push(x);
        push(y);

        if(a.size() < b.size()){
            a.push(mid);
            mid = -b.top();
            b.pop();
        }

        else if(a.size() > b.size()){
            b.push(-mid);
            mid = a.top();
            a.pop();
        }
        printf("%d\n",mid);
    }

    return 0;
}