#include <bits/stdc++.h>

using namespace std;
int n;
int con[105][105],h[105][105],DP[105][105],bl[105][105];
char s[105];
struct data{
    int x,y;
    bool operator<(const data&t)const{
        return x<t.x;
    }
};
vector<data> ans;

///DP[i][j]=i번째 점부터 j번쨰 점까지 하얀점과 검은점의 개수가 같을때 연결된 길이의 최솟값
///con[i][j]=i와 j를 연결할 때 i와 연결된 것
///h[i][j]=i와 j를 연결할때 높이
///bl[i][j]=i번쨰 점부터 j번째 점까지의 검은점의 수

void connect(int st,int en){
    ans.push_back({st+1,con[st][en]});
	if(con[st][en] != st+2) connect(st+1,con[st][en]-1);
	if(con[st][en] != en) connect(con[st][en], en);
}

void res(){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            DP[i][j]=1e9;
        }
    }

    for(int i=0;i<n;i++) {
		bl[i][i+1]=s[i]-'0';
		for(int j=i+2;j<=n;j++){
			bl[i][j]=bl[i][j-1]+(s[j-1]-'0');
		}
	}
}

int dynamic(){
    for(int j=2;j<=n;j+=2){
		for(int i=0;i<=n-j;i++){
			if(bl[i][i+j] != j/2) continue;

            if(s[i] + s[i+j-1] == '0' + '1'){
				h[i][i+j] = h[i+1][i+j-1] + 1;
				con[i][i+j] = i + j;
				DP[i][i+j] = 2 * h[i][i+j] + (j-1) + DP[i+1][i+j-1];
			}

			for(int k=i+2;k<i+j;k+=2){
				if(DP[i][i+j] > DP[i][k] + DP[k][i+j]){
					DP[i][i+j] = DP[i][k] + DP[k][i+j];
					con[i][i+j] = k;
					h[i][i+j] = max(h[i][k],h[k][i+j]);
				}
			}
		}
	}

	return DP[0][n];
}

int main()
{
    scanf("%d %s",&n,s);

    res();
    printf("%d\n",dynamic());
    connect(0,n);

    sort(ans.begin(),ans.end());
    for(auto i:ans) printf("%d %d\n",i.x,i.y);

    return 0;
}