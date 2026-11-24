#include <stdio.h>
int main(){

    int s,e;
    while(1){
        scanf("%d %d",&s, &e);
        if(s >= 2 && s <= 9 && e >= 2 && e <= 9) break;
        printf("INPUT ERROR!\n");
    }

    if(s >= e){
        for(int j=1;j<=9;j++){
            for(int k = s;k >= e;k--){
                printf("%d * %d = %2d   ",k,j,k*j);
            }
            printf("\n");
        }
    }

    else{
        for(int j=1;j<=9;j++){
            for(int k = s;k <= e;k++){
                printf("%d * %d = %2d   ",k,j,k*j);
            }
            printf("\n");
        }
    }

    return 0;
}