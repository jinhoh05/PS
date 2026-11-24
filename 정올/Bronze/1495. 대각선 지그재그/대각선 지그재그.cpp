#include <stdio.h>
int map[101][101];
int main(){

    int n;
    scanf("%d",&n);
    int i;
    int j;
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n+1;j++){
            map[i][j]=-1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=0;
        }
    }
    i=j=1;
    int cnt=1;
    map[i][j]=cnt;
    cnt++;
    while(1){
            if(map[i+1][j] == 0){
                i++;
                map[i][j]=cnt;
                cnt++;
            }
            else{
                j++;
                map[i][j]=cnt;
                cnt++;
            }

            while(1){
                if(map[i-1][j+1]==0){
                    i--;
                    j++;
                    map[i][j]=cnt;
                    cnt++;
                }
                else if(map[i][j+1]==0){

                    j++;
                    map[i][j]=cnt;
                    cnt++;
                    break;
                }
                else{
                    i++;
                    map[i][j]=cnt;
                    cnt++;
                    break;
                }

            }


            while(1){
                if(map[i+1][j-1]==0){
                    i++;
                    j--;
                    map[i][j]=cnt;
                    cnt++;
                }
                else{
                    break;
                }
            }

            if(cnt == n*n+1){
                break;
            }

    }


    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
    printf("\n");
   }
    return 0;
}