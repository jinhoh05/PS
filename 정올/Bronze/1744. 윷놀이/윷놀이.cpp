#include <bits/stdc++.h>

using namespace std;
int play[5],up,down;

int main()
{
    for(int i=1;i<=3;i++){
        up=down=0;
        for(int j=1;j<=4;j++){
            scanf("%d",&play[j]);
            if(play[j]) up++;
            else down++;
        }
        if(up==0) printf("D\n");
        else if(up==1) printf("C\n");
        else if(up==2) printf("B\n");
        else if(up==3) printf("A\n");
        else printf("E\n");
    }

    return 0;
}