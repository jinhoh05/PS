#include <stdio.h>
int main(){

    int m,n;
    scanf("%d",&n);
    char a[101][101];
    char cnt = 'A';

    for(int i=n;i>0;i--){
        for(int j=n;j>0;j--){
            a[j][i]=cnt;
            cnt++;
            if(cnt == 'Z' + 1){
                cnt='A';
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}