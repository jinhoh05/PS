#include <bits/stdc++.h>

char a[50];
long long b[50];

int main()
{	
	int i, k;
	
	scanf("%s", a+1); 
	k=strlen(a+1); 
	
	b[0]=1;
	b[1]=1;
	
	a[1]-='0';  

	for(i=2;i<=k;i++)
	{
		a[i]-='0';
		
		if(a[i]!=0) 
			b[i]=b[i-1];
			
		if((a[i-1]*10)+a[i] <= 34 && a[i-1] != 0) 
			b[i]+=b[i-2];
		
	}
	printf("%lld", b[k]);
    
	return 0;
}