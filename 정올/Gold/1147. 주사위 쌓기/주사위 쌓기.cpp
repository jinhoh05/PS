#include <bits/stdc++.h>

using namespace std;
int n,dice[10010][10];

int where(int a, int num){
    a++;
    for(int i=1;i<=6;i++){
        if(dice[a][i]==num) return i;
    }
}

int up(int a){
    if(a==1) return 6;
    else if(a==2) return 4;
    else if(a==3) return 5;
    else if(a==4) return 2;
    else if(a==5) return 3;
    else if(a==6) return 1;
}

int top(){
    int ans=0, sum, a, aa;

    for(int i=1;i<=6;i++){
        sum=0;
        a=i;
        for(int j=1;j<=n;j++){
            aa=up(a);

            if(dice[j][a] != 6 && dice[j][aa] != 6) sum+=6;
            else if(dice[j][a] != 5 && dice[j][aa] != 5) sum+=5;
            else sum+=4;

            a=where(j, dice[j][aa]);
        }

        if(sum > ans) ans = sum;
    }

    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            scanf("%d",&dice[i][j]);
        }
    }

    printf("%d", top());

    return 0;
}