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
    int sum=0;

    for(int i=0;i<n;i++){
        scanf(" %c",&a);

        if(a == '+'){
            cnt--;
            stack[cnt-1] = stack[cnt-1] + stack[cnt];
        }
        else if(a == '-'){
            cnt--;
            stack[cnt-1] = stack[cnt-1] - stack[cnt];
        }
        else if(a == '/'){
            cnt--;
            stack[cnt-1] = stack[cnt-1] / stack[cnt];
        }
        else if(a == '*'){
            cnt--;
            stack[cnt-1] = stack[cnt-1] * stack[cnt];
        }

        else{
            stack[cnt++] = a - '0';
        }
    }

    printf("%d",stack[0]);

    return 0;
}