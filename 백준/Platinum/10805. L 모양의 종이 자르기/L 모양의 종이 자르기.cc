#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

int rect[55][55];
int DP[55][55][55][55];

void rectangle(){
    for(int i=1;i<=50;i++){
        for(int j=1;j<=50;j++){
            rect[i][j] = INF;

            if(i == j) rect[i][j] = 1;

            else if(i >= j * 3) rect[i][j] = rect[i - j][j] + 1;

            else{
                for(int k=1;k<=j/2;k++){
                    rect[i][j] = min(rect[i][j], rect[i][k] + rect[i][j - k]);
                }

                for(int k=1;k<=i/2;k++){
                    rect[i][j] = min(rect[i][j], rect[k][j] + rect[i - k][j]);
                }
            }
        }
    }
}

int func(int h1, int w1, int h2, int w2){
    int &ret = DP[h1][w1][h2][w2];

    if(ret != -1) return ret;

    int h3 = h1 - h2;
    int w3 = w1 - w2;

    ret = INF;

    for(int i=1;i<h1;i++){
        if(i < h2) ret = min(ret, rect[i][w3] + func(h1 - i, w1, h2 - i, w2));
        else if(i == h2) ret = min(ret, rect[i][w3] + rect[h1 - i][w1]);
        else ret = min(ret, rect[h1 - i][w1] + func(i, w1, h2, w2));
    }

    for(int i=1;i<w1;i++){
        if(i < w3) ret = min(ret, rect[h1][i] + func(h1, w1 - i, h2, w2));
        else if(i == w3) ret = min(ret, rect[h1][i] + rect[h3][w2]);
        else ret = min(ret, rect[h3][w1 - i] + func(h1, i, h2, i - w3));
    }

    return ret;
}

int main()
{
    memset(DP, -1, sizeof(DP));

    int h1, h2, w1, w2;

    scanf("%d %d %d %d", &h1, &w1, &h2, &w2);

    rectangle();

    printf("%d", func(h1, w1, h2, w2));

    return 0;
}
