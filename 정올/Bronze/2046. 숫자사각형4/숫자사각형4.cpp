#include <stdio.h>
int main(){

    int m,n;
    scanf("%d %d",&n,&m);
    int a[101][101];
    int cnt;
    int sum=0;
    for(int i=1;i<=n;i++){
        cnt=n;
        sum=i;
        for(int j=1;j<=n;j++){
           if(m==1){
                a[i][j]=i;
           }
           else if(m == 2){
                if(i % 2 == 1){
                    a[i][j]=j;
                }
                else{
                    a[i][j]=cnt;
                    cnt--;
                }
           }
           else{
                a[i][j]=sum;
                sum=sum+i;
           }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
    printf("\n");
    }


    return 0;
}