#include <bits/stdc++.h>

using namespace std;
/// 세그 트리 높이는 4*n;

/// node=내가 바꿀 번호
/// s=시작번호, e=끝번호
/// idx=몇번째 배열에, t=넣을 숫자

/// fs=질문 시작번호, fe=질문 끝번호

int n,q;
int arr[50005];
int tree[200005];

void update(int node, int s, int e, int idx, int t){
    if(idx < s || idx > e) return;
    if(s == e){
        tree[node]=t;
        return;
    }
    update(node*2, s, (s+e)/2, idx, t);
    update(node*2+1, (s+e)/2+1, e, idx, t);

    tree[node]=max(tree[node*2],tree[node*2+1]);
}

const int INF=987654321;
int query(int node, int s, int e, int fs, int fe){
    if(e < fs || fe < s) return -INF;
    if(fs <= s && e <= fe) return tree[node];
    return max(query(node*2, s, (s+e)/2, fs, fe), query(node*2+1, (s+e)/2+1, e, fs, fe));
}

int main()
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        update(1,1,n,i,arr[i]);
    }

    for(int i=1;i<=q;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",query(1, 1, n, a, b));
    }

    return 0;
}