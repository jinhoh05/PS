#include <stdio.h>
int main(){

    int m,n;
    scanf("%d %d",&n, &m);
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",cnt);
            cnt++;
        }
        printf("\n");
    }

    return 0;
}