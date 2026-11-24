#include <bits/stdc++.h>

using namespace std;
int n;
int heap[500005];

void push_heap(int hn){
    int c = hn;
    while(c > 1 && heap[c] > heap[c/2]){
        swap(heap[c], heap[c/2]);
        c /= 2;
    }
}

void pop_heap(int hn){
    int p=1, c=2;
    swap(heap[1], heap[hn--]);
    while(c <= hn){
        if( c < hn && heap[c + 1] > heap[c]) c++;
        if(heap[c] <= heap[p]) break;
        swap(heap[p], heap[c]);
        p = c, c *= 2;
    }
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&heap[i]);
        push_heap(i);
    }

    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");

    for(int i=n;i>=1;i--){
        pop_heap(i);
    }

    for(int i=1;i<=n;i++){
        printf("%d ",heap[i]);
    }

    return 0;
}