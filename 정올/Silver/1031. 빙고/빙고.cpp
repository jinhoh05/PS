#include <bits/stdc++.h>


using namespace std;

int a[6][6]={0};
int b[6][6];
int cnt=0;
int sum=0, flag=0;
void cmp(int x,int y){
    int j=0;


    for(int i=0;i<5;i++){
        if(a[x][i] != -1) break;
        j++;
    }
    if(j==5) cnt++;
    j=0;
    for(int i=0;i<5;i++){
        if(a[i][y] != -1) break;
        j++;
    }
    if(j==5) cnt++;
    j=0;
    int q=4;

    if(x == y){

        for(int i=0;i<5;i++){
            if(a[i][i] != -1) break;
            j++;
        }

        if(j==5) cnt++;
    j=0;
    }

    if(x + y == 4){

        for(int i=0;i<5;i++){
            if(a[i][q] != -1) break;
            q--;
            j++;
        }

        if(j==5) cnt++;
    j=0;
    }
    //printf("%d",cnt);
    if(cnt >= 3){
        printf("%d",sum);
        flag=1;
        return;
    }

    return;
}

int bingo(int i,int j){

    for(int g=0;g<5;g++){
        for(int k=0;k<5;k++){
            if(a[g][k] == b[i][j]){
                a[g][k]=-1;
                cmp(g,k);
                return 0;
            }
        }
    }


}

int main()
{

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int f=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            sum++;
            bingo(i,j);
            if(flag) break;
            /*for(int g=0;g<5;g++){
                for(int k=0;k<5;k++){
                    printf("%d ",a[g][k]);
                }
                printf("\n");
            }
            printf("\n");*/

        }
        if(flag)break;
    }

    return 0;
}