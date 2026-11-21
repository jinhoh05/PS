#include <stdio.h>
 
int main() {
 
    int S, M, L, B;
    scanf("%d %d %d", &S, &M, &L);
 
    B = 1 * S + 2 * M + 3 * L;
 
    if (B >= 10) printf("happy");
    else printf("sad");
 
    return 0;
}