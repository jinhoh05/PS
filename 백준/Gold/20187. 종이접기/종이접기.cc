#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int K, H;
    scanf("%d ", &K);
 
    int left = 0;
    int right = pow(2, K);
    int top = 0;
    int bot = pow(2, K);
 
    int lt[4][2][2];
    lt[0][0][0] = 0;
    lt[0][0][1] = 2;
    lt[0][1][0] = 1;
    lt[0][1][1] = 3;
 
    lt[1][0][0] = 1;
    lt[1][0][1] = 3;
    lt[1][1][0] = 0;
    lt[1][1][1] = 2;
 
    lt[2][0][0] = 2;
    lt[2][0][1] = 0;
    lt[2][1][0] = 3;
    lt[2][1][1] = 1;
 
    lt[3][0][0] = 3;
    lt[3][0][1] = 1;
    lt[3][1][0] = 2;
    lt[3][1][1] = 0;
 
    for(int k=0;k<2*K;k++){
        char c;
        scanf("%c ", &c);
        
        switch(c){
            case 'D': top = (top+bot)/2; break;
            case 'U': bot = (top+bot)/2; break;
            case 'R': left = (left+right)/2; break;
            case 'L': right = (left+right)/2; break;
        }
    }
 
    scanf("%d", &H);
 
    for(int y=0;y<pow(2, K);y++){
        for(int x=0;x<pow(2, K);x++){
            printf("%d%s", lt[H][abs(left-x)%2][abs(top-y)%2], x==pow(2,K)-1?"":" ");
        }
        if(y == pow(2, K) - 1) break;
        printf("\n");
    }
}