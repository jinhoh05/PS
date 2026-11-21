#include <bits/stdc++.h>
 
using namespace std;
int n;
int plank[20005];
int hap;
long long int ans;
int a,b;
 
void push_heap(int hn){
    int c = hn;
    while(c > 1 && plank[c] > plank[c/2]){
        swap(plank[c], plank[c/2]);
        c /= 2;
    }
}
 
void pop_heap(int hn){
    int p=1, c=2;
    swap(plank[1], plank[hn--]);
    while(c <= hn){
        if(c < hn && plank[c+1] > plank[c]) c++;
        if(plank[c] <= plank[p]) break;
        swap(plank[p], plank[c]);
        p=c,c*=2;
    }
}
 
void minpush_heap(int hn){
    int c = hn;
    while(c > 1 && plank[c] < plank[c/2]){
        swap(plank[c], plank[c/2]);
        c /= 2;
    }
}
 
void minpop_heap(int hn){
    int p=1, c=2;
    swap(plank[1], plank[hn--]);
    while(c <= hn){
        if(c < hn && plank[c+1] < plank[c]) c++;
        if(plank[c] >= plank[p]) break;
        swap(plank[p], plank[c]);
        p = c, c *= 2;
    }
}
 
int main()
{
    scanf("%d",&n);
 
    for(int i=1;i<=n;i++){
        scanf("%d",&plank[i]);
        push_heap(i);
    }
 
    for(int i=n;i>=1;i--){
        pop_heap(i);
    }
 
    if(n == 1){
        printf("%d",plank[1]);
        return 0;
    }
 
    int hn=n;
 
    for(int i=1;i<n;i++){
        hap=plank[1];
        minpop_heap(hn);
        hn--;
        hap+=plank[1];
        minpop_heap(hn);
 
        plank[hn]=hap;
        ans+=hap;
 
        minpush_heap(hn);
    }
 
    printf("%lld",ans);
    return 0;
 
}