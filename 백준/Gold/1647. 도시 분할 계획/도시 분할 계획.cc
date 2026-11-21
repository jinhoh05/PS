#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans, divide;
int parent[100005];

struct Data{

    int a, b, c;

    bool operator<(const Data &t)const{
        if(c > t.c) return true;
        else return false;
    }

};

priority_queue<Data> pq;

int getParent(int x){
    if(x == parent[x]) return x;
    else return parent[x] = getParent(parent[x]);
}

void setUion(int a, int b) {
    int x = getParent(a);
    int y = getParent(b);

    if(x < y) parent[y] = x;
    else parent[x] = y;
    return;
}

bool isUnion(int a, int b){
    if(getParent(a) == getParent(b)) return true;
    else return false;
}

int main(){

    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        pq.push({a, b, c});
    }

    for(int i=1; i<=n; i++) parent[i]=i;

    while(!pq.empty()){
        Data t = pq.top();
        pq.pop();

        if(!isUnion(t.a, t.b)){
            
            setUion(t.a, t.b);
            ans+=t.c;
            divide=t.c;
        }
    }

    printf("%d", ans - divide);

    return 0;
}
