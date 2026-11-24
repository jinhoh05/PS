#include <stdio.h>

using namespace std;
int stack[105];

int main()
{
    int cnt=0;
    char a;
    int d;
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf(" %c",&a);
        if(a == 'i'){
            scanf("%d",&d);
            stack[cnt++]=d;
        }
        if(a == 'c') printf("%d\n",cnt);
        if(a == 'o'){
            if(cnt==0){
                printf("empty\n");
            }
            else {
                printf("%d\n",stack[cnt-1]);
                cnt--;
            }
        }
    }



    return 0;
}