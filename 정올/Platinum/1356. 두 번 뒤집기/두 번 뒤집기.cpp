#include <bits/stdc++.h>

using namespace std;
int n,see=1,cnt;
int arr[10005],a[10005],answer[3][3];

void change(int i, int j, int k){
    if(i == j) return;
    answer[k][1]=i, answer[k][2]=j;

    while(i<=j){
        swap(a[i], a[j]);
        i++, j--;
    }
}

int check(){
    cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i] == i) cnt++;
    }
    if(cnt==n) return 1;
    return 0;
}

void where(int k,int lev){
     if(k == 1){
        for(int i=1;i<=n;i++){
            if(a[i] != i){
                for(int j=1;j<=n;j++){
                    if(a[j] == i){
                        change(i,j,lev);
                        return;
                    }
                }
            }
        }
    }

    else{
        for(int i=n;i>=1;i--){
            if(a[i] != i){
                for(int j=1;j<=n;j++){
                    if(a[j] == i){
                        change(j,i,lev);
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        if(arr[i] == i) cnt++;
        a[i]=arr[i];
    }

    if(cnt == n){
        printf("1 1\n1 1");
        return 0;
    }

    for(int i=1;i<=2;i++){
        cnt=0;
        for(int j=1;j<=2;j++){
            where(i,j);
            if(j == 1 && check()){
                printf("%d %d\n1 1",answer[1][1], answer[1][2]);
                return 0;
            }
        }

        if(check()){
            printf("%d %d\n%d %d",answer[1][1], answer[1][2], answer[2][1], answer[2][2]);
            return 0;
        }
        for(int k=1;k<=n;k++) a[k]=arr[k];
    }

    return 0;
}