#include <bits/stdc++.h>

using namespace std;
int D1,D2,ans;
int vt[2010][2010];

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    scanf("%d %d",&D1,&D2);

    for(int i=D1;i<=D2;i++){
		for(int j=1;j<=i;j++){
			int g=gcd(i,j);
			if(vt[i/g][j/g] == 0){
				vt[i/g][j/g] = 1;
				ans++;
			}
		}
	}

    printf("%d",ans);
    return 0;
}