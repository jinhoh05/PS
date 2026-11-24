#include <stdio.h>
int main(){

    int m,n;

    scanf("%d %d",&n,&m);

    if(n > 100 || n < 1 || m > 3 || m < 1){
        printf("INPUT ERROR!");
        return 0;
    }
    int cnt=1;
    if(m==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                printf("*");
            }
            printf("\n");
        }
    }

    else if(m==2){
        for(int i=0;i<n;i++){
            for(int j=n;j>i;j--){
                printf("*");
            }
            printf("\n");
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){
                printf(" ");
            }
            for(int k=1;k<=cnt;k++){
                printf("*");
            }
            printf("\n");
            cnt=cnt+2;
        }
    }
    return 0;
}