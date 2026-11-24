#include <stdio.h>

using namespace std;
int queue[105];

int main()
{
    char a;
    int d;
    int n;
    scanf("%d",&n);


    int fro=0;
    int end=0;

    for(int i=0;i<n;i++){
        scanf(" %c",&a);
        if(a == 'i'){
            scanf("%d",&d);
            queue[end++]=d;
        }
        if(a == 'c') printf("%d\n",end - fro);
        if(a == 'o'){
            if(end - fro == 0){
                printf("empty\n");

            }
            else {
                printf("%d\n",queue[fro]);
                fro++;
            }
        }
    }



    return 0;
}