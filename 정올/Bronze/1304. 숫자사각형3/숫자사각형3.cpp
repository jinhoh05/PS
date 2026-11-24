#include <stdio.h>
int main(){

    int m,n;
    scanf("%d",&n);
    int a[101][101];
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[j][i]=cnt;
            cnt++;

        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
    printf("\n");
    }


    return 0;
}