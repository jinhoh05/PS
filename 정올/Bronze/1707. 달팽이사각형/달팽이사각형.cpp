#include <stdio.h>

int map[101][101]={0};
//a==5
//b==1
//y==1
//x==1
//j==1
void move(int a,int b,int y,int x,int j){

    map[y][x]=b;
    b++;
    if(b == a * a + 1){
    //printf("%d",map[1][1]);
        return;
    }

    if(j==1){
        x++;
        if(map[y][x]== 0 ){
            move(a,b,y,x,1);
        }
        else{
            x--;
            y++;
            move(a,b,y,x,2);
        }
    }

    else if(j==2){
        y++;
        if(map[y][x]== 0 ){
            move(a,b,y,x,2);
        }
        else{
            y--;
            x--;
            move(a,b,y,x,3);
        }
    }

    else if(j==3){
        x--;
        if(map[y][x]== 0 ){
            move(a,b,y,x,3);
        }
        else{
            x++;
            y--;
            move(a,b,y,x,4);
        }
    }
    else{
        y--;
      if(map[y][x]== 0){
            move(a,b,y,x,4);
        }
        else{
            y++;
            x++;
            move(a,b,y,x,1);
        }
    }


}

int main(){

    int n;
    scanf("%d",&n);

    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            map[i][j]=-1;
        }
    }
    int cnt=1;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=0;
        }
    }
    int X=1;
    int Y=1;
    int i=1;
    move(n,1,1,1,1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
    printf("\n");
    }

    return 0;
}