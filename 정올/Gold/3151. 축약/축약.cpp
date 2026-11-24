#include <bits/stdc++.h>

using namespace std;
int n,p,ans,l_A,l_B,DP[1005][1005];

///DP[i][j]=A문자열에 첫번째부터 i번째까지의 문자
///         B문자열에 첫번째부터 j번째까지의 문자
///         축약가능하면 1을 저장한다.
///만약 A[i]가 대문자라면 DP[i][j]=DP[i-1][j-1]
///만약 A[i]가 소문자면 DP[i][j]=DP[i-1][j]
///만약 A[i]가 소문자인데 대문자로 바꿨을떄 A[i]가 B[j]랑 같아면 DP[i][j]|=DP[i-1][j-1];

void dynamic(){
    char A[1005],B[1005];

    memset(DP,0,sizeof(DP));
    scanf("%s %s",A+1,B+1);
    l_A=strlen(A+1),l_B=strlen(B+1);

    for(int i=0;i<=l_B;i++) DP[0][i]=0;
    DP[0][0]=1;

    for(int i=1;i<=l_A;i++){
        for(int j=0;j<=l_B;j++){
            if(isupper(A[i])!=0){
                if(A[i]==B[j] && j>=1) DP[i][j]=DP[i-1][j-1];
            }
            else if(A[i]-32==B[j] && j>=1) DP[i][j]=max(DP[i-1][j-1],DP[i-1][j]);
            else DP[i][j]=DP[i-1][j];
        }
    }

    if(DP[l_A][l_B]) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        dynamic();
    }

    return 0;
}