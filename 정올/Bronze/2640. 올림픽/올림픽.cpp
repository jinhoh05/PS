#include <bits/stdc++.h>

using namespace std;
int n,k,ans=1,l;
int **Ol;

int main()
{
	scanf("%d %d",&n,&k);

	Ol=(int**)malloc(sizeof(int*)*4);
    for(int i=0;i<4;i++) Ol[i] = (int *)malloc(sizeof(int) * n);

    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&Ol[0][i],&Ol[1][i],&Ol[2][i],&Ol[3][i]);
    }

    for(int i=0;i<n;i++){
		if(Ol[0][i]==k){
            l=i;
			break;
		}
    }

    for(int i=0;i<n;i++){
		if(i==l) continue;

		if(Ol[1][l] < Ol[1][i]) ans++;
		else if(Ol[1][l]==Ol[1][i] && Ol[2][l]<Ol[2][i]) ans++;
		else if(Ol[1][l]==Ol[1][i] && Ol[2][l]==Ol[2][i] && Ol[3][l]<Ol[3][i]) ans++;
	}

	printf("%d",ans);


    return 0;
}