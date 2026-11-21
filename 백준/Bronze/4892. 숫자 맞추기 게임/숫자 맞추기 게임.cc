#include<stdio.h>

int main() {
	int n = 1;
	int count = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		printf("%d. ", count++);
		if ((n * 3 % 2) == 1) { 
			n = (3* n + 1) / 2 *3 / 9;
			printf("odd %d\n",n);
		}
		else {
			n = 3* n  / 2 *3 / 9;
			printf("even %d\n", n);
		}
	}
    return 0;
}

