#include <bits/stdc++.h>

using namespace std;
int n,big,bigger,ans=1,num[1005][6],vt[1005][1005];

int check(){
    int hap=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=5;j++){
            for(int k=1;k<=n;k++){
                if(num[i][j] == num[k][j] && i != k && vt[i][k] != 1){
                    cnt++;
                    vt[i][k]=1;
                }
            }
        }
        if(hap < cnt){
            hap=cnt;
            ans=i;
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",&num[i][j]);
        }
    }

    printf("%d",check());

    return 0;
}