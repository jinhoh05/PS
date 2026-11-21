#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int c = n / 2;
	
	if(n % 6 == 2)
	{
	    for(int i = 1; i < c + 1; i++)
	        printf("%d\n", i * 2);
	    
	    printf("3\n1");
	    
	    for(int i = 3; i < c; i++)
	        printf("%d\n", i * 2 + 1);
	    printf("5");
	}
	
	if(n % 6 == 3)
	{
	    for(int i = 2; i < c + 1; i++)
	        printf("%d\n", i * 2);
	    
	    printf("2");
	    
	    for(int i = 2; i < c + 1; i++)
	        printf("%d\n", i * 2 + 1);
	    
	    printf("1\n3");
	}
	
	
	else
	{
	    for(int i = 1; i < c + 1; i++)
	        printf("%d\n%d\n", i + c, i);
	    
	    if(n & 1) printf("%d", n);
	}
	
	return 0;
}