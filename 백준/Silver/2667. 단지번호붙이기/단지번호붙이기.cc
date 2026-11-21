#include <bits/stdc++.h>
  
using namespace std;
int n,house[26][26],ans,big;
int vt[26][26];
int num[26];
  
void floyd(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n) return;
    if(vt[x][y]) return;
     
    big++;
    vt[x][y] = 1;
     
    floyd(x, y - 1);
    floyd(x + 1, y);
    floyd(x, y + 1);
    floyd(x - 1, y);
}
  
int main()
{
    scanf("%d",&n);
  
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d", &house[i][j]);
            if(house[i][j] == 0) vt[i][j] = 1;
        }
    }
     
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vt[i][j] == 0){
                big = 0;
                floyd(i, j);
                num[++ans] = big;
            }
        }
    }
  
    sort(num + 1, num + ans + 1);
     
    printf("%d\n", ans);
    for(int i=1;i<=ans;i++){
        printf("%d\n", num[i]);
    }
  
    return 0;
}