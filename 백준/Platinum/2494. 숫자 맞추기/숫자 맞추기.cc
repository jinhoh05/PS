 #include <cstdio>

#include <cstring>
 
int D[10001][10];
 
int From[10001];
int To[10001];
 
int Dir[10001][10];
int Cost[10001][10];
 
int f(int idx, int n, int turn) {
 
    if (idx == n) return 0;
 
    int& ret = D[idx][turn];
    if (ret != -1) return ret;
 
    int cur = (From[idx] + turn)%10;
 
    //left
    int leftTurn = (To[idx] - cur + 10) % 10;
    int leftCostSum = f(idx + 1, n, (turn + leftTurn) % 10) + leftTurn;
 
    //right
    int rightTurn = (cur - To[idx] + 10) % 10;
    int rightCostSum = f(idx + 1, n, turn) + rightTurn;
 
    if (rightCostSum > leftCostSum) {
        ret = leftCostSum;
        Dir[idx][turn] = 1;
        Cost[idx][turn] = leftTurn;
    }
    else {
        ret = rightCostSum;
        Dir[idx][turn] = -1;
        Cost[idx][turn] = rightTurn;
    }
 
    return ret;
}
 
void print(int idx, int n, int turn) {
     
    if (idx == n) return;
 
    int move = Dir[idx][turn] * Cost[idx][turn];
 
    if (move != 0) printf("%d %d\n", idx + 1, move);
    if (Dir[idx][turn] > 0) print(idx + 1, n, (turn + move + 10) % 10);
    else print(idx + 1, n, turn);
}
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) scanf("%1d", &From[i]);
    for (int i = 0; i < n; i++) scanf("%1d", &To[i]);
 
    memset(D, -1, sizeof(D));
    printf("%d\n", f(0,n,0));
    print(0, n, 0);
 
    return 0;
}
