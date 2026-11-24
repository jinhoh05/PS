#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n;
int lotto[55];
int loto[55];
int sum=0;
int point=0;
void change(int cnt){
    if(cnt > 6){
        for(int i=1;i<=6;i++){
            printf("%d ",lotto[loto[i]]);
        }
        printf("\n");
        return;
    }
    for(int i=loto[cnt-1]+1;i<=n;i++){
        loto[cnt]=i;
        change(cnt+1);
    }
}


int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&lotto[i]);
        if(lotto[i] > sum) sum=lotto[i];
    }

    sort(lotto,lotto+n);

    change(1);

}