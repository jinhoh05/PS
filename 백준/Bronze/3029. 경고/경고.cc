#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int h1, m1, s1, h2, m2, s2;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
 
    int start = 3600 * h1 + 60 * m1 + s1;
    int finish = 3600 * h2 + 60 * m2 + s2;
 
    int wait = ((finish + 24*3600) - start) % (24*3600);
    int h = (wait / 3600);
    int m = (wait % 3600) / 60;
    int s = (wait % 3600) % 60;
 
    if(start == finish) printf("24:00:00\n");
    else printf("%02d:%02d:%02d\n", h, m, s);
    
    return 0;
}
 