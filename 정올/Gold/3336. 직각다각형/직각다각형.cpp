#include <bits/stdc++.h>
using namespace std;

vector<int> check_x, check_y;
int n, x, y, x1, y3, x2, y2, _y[1000010], _x[1000010], ans;
pair<int, int> polygon[100010];

int main(){
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        scanf("%d %d",&x,&y);
        x+=500000, y+=500000;
        polygon[i] = {x, y};
        check_x.push_back(x);
        check_y.push_back(y);
    }

    polygon[n] = polygon[0];
    for(int i=0;i<n;i++){
        x1 = polygon[i].first, y3 = polygon[i].second;
        x2 = polygon[i+1].first, y2 = polygon[i+1].second;

        if(x1 != x2){
            if(x1 > x2) swap(x1, x2);
            for(int j=x1+1;j<=x2;j++) _x[j]++;
        }

        if(y3 != y2){
            if(y3 > y2) swap(y3, y2);
            for(int j=y3+1;j<=y2;j++) _y[j]++;
        }
    }

    for(int a : check_x) ans = max(ans, _x[a]);
    for(int a : check_y) ans = max(ans, _y[a]);

    printf("%d",ans);
    return 0;
}