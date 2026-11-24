#include <bits/stdc++.h>

using namespace std;
char s[505];
int n,DP[505][505];

///DP[i][j]=i번째 문자부터 j번째 문자까지의 최대 문자의길이
///만약 끝 두문자가 a-t이거나 g-c이 DP[i][j]=DP[i+1][j-1]+2;
///X,Y가 KOI 문자열이어서 XY문자열이라면 DP[i][j]=max(DP[i][j],DP[i+((j-i)+1-k)][j-k]);

int dynamic(){
    for(int j=2;j<=n;j++){
        for(int i=j-1;i>=1;i--){
            if(s[i]=='a' && s[j]=='t' || s[i]=='g' && s[j]=='c') DP[i][j]=DP[i+1][j-1]+2;

            int b=0;
            for(int k=1;k<=j-i;k++){
                int temp=DP[i+((j-i)+1-k)][j]+DP[i][j-k];
                if(b<temp) b=temp;
            }
            DP[i][j]=max(DP[i][j],b);
        }
    }

    return DP[1][n];
}

int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);


    printf("%d",dynamic());

    return 0;
}