#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1025][1025],n,cnt,num[2];

int check(int lx,int ly, int rx, int ry){
    int checker=arr[ly][lx];
    for(int i=ly;i<=ry;i++){
        for(int j=lx;j<=rx;j++){
            if(checker!=arr[i][j]) return 0;
        }
    }
    return 1;
}

void checking(int lx,int ly, int rx, int ry){
    if(check(lx,ly,rx,ry)){
        printf("%d",arr[ly][lx]);
        return;
    }
    else{
        printf("X");
    }

    int mx=(lx+rx)/2,my=(ly+ry)/2;

    checking(lx,ly,mx,my);
    checking(mx+1,ly,rx,my);
    checking(lx,my+1,mx,ry);
    checking(mx+1,my+1,rx,ry);

    return;
}
int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    checking(1,1,n,n);


    return 0;
}