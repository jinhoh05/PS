#include <bits/stdc++.h>
 
using namespace std;
string s,a,b;
int ans,DP_a[105][105],DP_b[105][105];
int len,len_a;
 
int dynamic(){
    for(int i=0;i<=len;i++){
        for(int j=0;j<=len_a;j++){
            if(s[i]==a[j]) DP_a[i+1][j+1]=DP_b[i][j]+DP_a[i+1][j];
            else DP_a[i+1][j+1]=DP_a[i+1][j];
        }
 
        for(int j=0;j<=len_a;j++){
            if(s[i]==b[j]) DP_b[i+1][j+1]=DP_a[i][j]+DP_b[i+1][j];
            else DP_b[i+1][j+1]=DP_b[i+1][j];
        }
    }
 
    return DP_a[len+1][len_a+1]+DP_b[len+1][len_a+1];
}
 
int main()
{
    cin >> s >> a >> b;
 
    len=s.size()-1,len_a=a.size()-1;
 
    for(int i=0;i<=len_a;i++) DP_a[0][i]=DP_b[0][i]=1;
 
    printf("%d",dynamic());
 
    return 0;
}