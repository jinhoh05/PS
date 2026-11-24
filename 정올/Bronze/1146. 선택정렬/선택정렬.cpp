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
    int k=0;
    int max;
    int sum=0;
    for(int i=0;i<n-1;i++){
        max=a[i];
        sum=i;
        for(int j=i;j<n;j++){
            if(a[j] < max){
                max=a[j];
                sum=j;
            }
        }

        a[sum]=a[i];
        a[i]=max;
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }

        //printf("%d",sum);
        printf("\n");


    }


    return 0;
}