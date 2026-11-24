#include <stdio.h>

using namespace std;


int main()
{
    int n;
    int a[105];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int max;
    int sum=0;
    for(int i=1;i<n;i++){
        max=a[i];
        for(int j=0;j<i;j++){
            if(a[i] < a[j]){
                for(int k=j;k<=i;k++){
                    sum=a[k];
                    a[k]=max;
                    max=sum;
                }
            }
        }

        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }

        printf("\n");


    }


    return 0;
}