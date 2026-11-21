#include<bits/stdc++.h>

using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);

int ABS(int a){return max(a,-a);}

long long ABS(long long a){return max(a,-a);}

long double ABS(long double a){return max(a,-a);}

int T[3100];

char in[3100][3100];

int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",in[i]);
	long long ret=0;
	for(int i=a-1;i>=0;i--){
		int tmp=0;
		for(int j=b-1;j>=0;j--){
			if(in[i][j]=='O')tmp++;
			if(in[i][j]=='I')T[j]++;
			if(in[i][j]=='J'){
				ret+=tmp*T[j];
			}
		}
	}
	printf("%lld\n",ret);
    return 0;
}