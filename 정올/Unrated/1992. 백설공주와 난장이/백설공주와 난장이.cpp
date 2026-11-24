#include <bits/stdc++.h>

using namespace std;
int n,pairy[15],ans,big,num;
int vt[26][26];

int main()
{
    for(int i=1;i<=7;i++){
        scanf("%d",&pairy[i]);
        if(pairy[i] > big){
            big=pairy[i];
            num=i;
        }
    }
    pairy[num]=0;
    printf("%d\n",big);
    big=0;

    for(int i=1;i<=7;i++){
        big=max(pairy[i],big);
    }
    printf("%d",big);

    return 0;
}