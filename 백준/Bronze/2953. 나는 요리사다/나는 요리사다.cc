#include<stdio.h>

int main() 
{
	int i,j,a,maxi, sum = 0, max = 0;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%d", &a);
			sum = sum + a;
			if (sum > max) {
				max = sum;
				maxi = i+1;
			}
		}
		sum = 0;
	}
	printf("%d %d", maxi, max);
}