#include <bits/stdc++.h>

using namespace std;
int n,a,a_card,b,b_card;
int card_a[5],card_b[5];

void check(){
    if(card_a[4] > card_b[4]) printf("A\n");
    else if(card_a[4] < card_b[4]) printf("B\n");

    else{
        if(card_a[3] > card_b[3]) printf("A\n");
        else if(card_a[3] < card_b[3]) printf("B\n");

        else{
            if(card_a[2] > card_b[2]) printf("A\n");
            else if(card_a[2] < card_b[2]) printf("B\n");

            else{
                if(card_a[1] > card_b[1]) printf("A\n");
                else if(card_a[1] < card_b[1]) printf("B\n");
                else printf("D\n");
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        memset(card_a,0,sizeof(card_a));
        memset(card_b,0,sizeof(card_b));

        scanf("%d",&a);
        for(int j=1;j<=a;j++){
            scanf("%d",&a_card);
            card_a[a_card]++;
        }

        scanf("%d",&b);
        for(int j=1;j<=b;j++){
            scanf("%d",&b_card);
            card_b[b_card]++;
        }

        check();
    }

    return 0;
}