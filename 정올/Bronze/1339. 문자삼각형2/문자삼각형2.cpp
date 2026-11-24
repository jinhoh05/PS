#include <iostream>

using namespace std;

int n,k;
char arr[110][110];
char a='A';

void triangle(int n){
    for(int i=0;i<n/2+1;i++){
        for(int j=n/2+1-i,k=n/2+1-i;j<=n/2+1+i;j++){
            arr[j][k]=a++;
            if(a>'Z') a='A';
        }
    }
}

int main()
{
    scanf("%d",&n);
    if(n>100 || n < 1 || n % 2 == 0) printf("INPUT ERROR");
    else triangle(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==0) printf("  ");
            else printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
