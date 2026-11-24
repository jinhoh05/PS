#include <stdio.h>
int cnt; 

void hanoi(int n, char from, char to, char temp){
    cnt++;
    if ( n == 1 ) {
        printf("1 : %c -> %c \n", from, to);
    } 
    else{
        hanoi(n-1, from, temp, to);
        printf("%d : %c -> %c \n", n, from, to);
        hanoi(n-1, temp, to, from);
    }
}

int main()
{
    int num;
     
    scanf("%d", &num);
     
    hanoi(num, '1', '3', '2');
}