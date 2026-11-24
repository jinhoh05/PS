#include <bits/stdc++.h>

using namespace std;
int n=1;
int cnt=1;
long long int heap[1505];
long long int hp[1505];
long long int hn=0,num;

void push_heap(){
    int c = hn;
    while(c > 1 && heap[c] < heap[c/2]){
        swap(heap[c], heap[c/2]);
        c /= 2;
    }
}

void pop_heap(){
    int p=1, c=2;
    heap[1]=heap[hn--];
    while(c <= hn){
        if(c < hn && heap[c+1] < heap[c]) c++;
        if(heap[c] >= heap[p]) break;
        swap(heap[p], heap[c]);
        p = c, c *= 2;
    }
}

int main()
{
    heap[++hn]=1;

    while(cnt <= 1500){
        num=heap[1];
        pop_heap();
        if(hp[cnt-1] == num) continue;

        hp[cnt++]=num;

        heap[++hn]=num*2;
        push_heap();

        heap[++hn]=num*3;
        push_heap();

        heap[++hn]=num*5;
        push_heap();
    }

    while(1){
        scanf("%d",&n);

        if(n==0) break;

        printf("%d\n",hp[n]);
    }

    return 0;
}