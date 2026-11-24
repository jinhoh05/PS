#include <iostream>
#include <stdio.h>
using namespace std;

char c[201][201]={0};
int main()
{
    int n;
    char a='A';
    scanf("%d",&n);
    int cnt=0,i=1,j=n;
    int b=n-1;
    int z=0;
    while(b>0){
        for(int k=0;k<b;k++){
            c[i++][j--]=a++;
            if(a > 'Z'){
                a='A';
            }
        }

        for(int k=0;k<b;k++){
            c[i++][j++]=a++;
            if(a > 'Z'){
                a='A';
            }
        }

        for(int k=0;k<b;k++){
            c[i--][j++]=a++;
            if(a > 'Z'){
                a='A';
            }
        }

        for(int k=0;k<b;k++){
            c[i--][j--]=a++;
            if(a > 'Z'){
                a='A';
            }
        }

        i++;
        b--;
    }
    c[i][j]=a;

    for(i=1;i<n*2;i++){
        for(j=1;j<n*2;j++){
            if(c[i][j] != 0){
                printf("%c ",c[i][j]);
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}