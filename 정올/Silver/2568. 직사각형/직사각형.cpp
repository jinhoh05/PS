#include <bits/stdc++.h>

using namespace std;

struct data{
    int x1, x2;
    int y1, y2;

    bool operator<(const data &t)const{
        if(x1 == t.x1) return y1 < t.y1;
        return x1 < t.x1;
    }
};

data dot[5];

void check()
{
    int x1 = dot[1].x1, x2 = dot[1].x2, y1 = dot[1].y1, y2 = dot[1].y2;
    int x3 = dot[2].x1, x4 = dot[2].x2, y3 = dot[2].y1, y4 = dot[2].y2;

    if(y2 < y3 || y4 < y1 || x2 < x3) printf("d");

    else if(y1 == y4 || y2 == y3)
    {
        if(x2 == x3) printf("c");
        else printf("b");
    }

    else if(x2 == x3)
    {
        if(y1 == y4 || y2 == y3) printf("c");
        else printf("b");
    }

    else printf("a");

    printf("\n");
}

int main()
{
    for(int i = 1; i <= 4; i++)
    {
        scanf("%d %d %d %d", &dot[1].x1, &dot[1].y1, &dot[1].x2, &dot[1].y2);
        scanf("%d %d %d %d", &dot[2].x1, &dot[2].y1, &dot[2].x2, &dot[2].y2);

        sort(dot + 1, dot + 3);

        check();
    }
    
    return 0;
}