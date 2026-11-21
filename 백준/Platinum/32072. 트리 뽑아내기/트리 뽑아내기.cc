#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int n, p, A[300010], H[300010];
vector<int> node[300010];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    scanf("%d", &n);
    
    for (int i = 2 ; i <= n ; ++i) {
        scanf("%d", &p);
        node[p].push_back(i);
    }
    
    for (int i = 1 ; i <= n ; ++i) {
        scanf("%d", &A[i]);
        H[A[i]] = i;
    }
    
    pq.push(A[1]);
    
    while (!pq.empty()) {
        int val = pq.top();
        int here = H[val];
        
        pq.pop();
        
        printf("%d\n", val);
        
        for (int there: node[here]) {
            pq.push(A[there]);
        }
    }
}