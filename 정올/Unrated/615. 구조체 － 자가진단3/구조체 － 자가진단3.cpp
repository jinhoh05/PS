#include <bits/stdc++.h>

using namespace std;

struct data{
    char name[20];
    int age,ag;

}buddy;
int main()
{
    data self;
    scanf("%s",buddy.name);
    scanf("%d",&buddy.age);
    scanf("%d",&buddy.ag);

    scanf("%s",self.name);
    scanf("%d",&self.age);
    scanf("%d",&self.ag);

    printf("%s ",buddy.name);
    printf("%d ",buddy.age);
    printf("%d\n",buddy.ag);

    printf("%s ",self.name);
    printf("%d ",self.age);
    printf("%d\n",self.ag);

    data hap;

    strcpy(hap.name,"avg");
    hap.age=(buddy.age+self.age)/2;
    hap.ag=(buddy.ag+self.ag)/2;

    printf("%s ",hap.name);
    printf("%d ",hap.age);
    printf("%d",hap.ag);

    return 0;
}