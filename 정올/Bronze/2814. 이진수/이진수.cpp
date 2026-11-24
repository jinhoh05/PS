#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int change(char t[])
{
    int i, len, ten=0;
    len = strlen(t);
    for (i=0; i<len; i++) {
        ten = ten*2+(t[i]-'0');  //앞자리까지의 값에 2를 곱하고 현재의 값을 더한다.
    }
    return ten;
}

int main()
{
    char two[35];
    scanf("%s", two);
    printf("%d\n", change(two));
    return 0;
}