#include <stdio.h>
int main(){

    int s,e;
    scanf("%d %d",&s, &e);
      

    if(s >= e){
        for(int k = s;k >= e;k--){
            for(int j=1;j<=9;j++){
                printf("%d * %d = %2d   ",k,j,k*j);
                if(j % 3 == 0){
                    printf("\n");
                }
            }
           printf("\n");
        }
    }

   
    else{
        for(int k = s;k <= e;k++){
            for(int j=1;j<=9;j++){
                printf("%d * %d = %2d   ",k,j,k*j);
                if(j % 3 == 0){
                    printf("\n");
                }
            }
           printf("\n");
        }
    }

    return 0;
}