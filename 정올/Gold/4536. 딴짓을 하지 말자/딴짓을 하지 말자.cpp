#include <bits/stdc++.h>

using namespace std;

int T, N;

struct data
{
    int x1, y1, x2, y2;
}dot[1005];

bool calc()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = i + 1; j <= N; j++)
        {
            if(dot[i].x1 == dot[i].x2)
            {
                if(dot[j].x1 == dot[j].x2)
                {
                    if(dot[i].x1 < dot[j].x1 || dot[i].x1 > dot[j].x1) continue;
                    if(dot[j].x1 < dot[i].x1 || dot[j].x1 > dot[i].x1) continue;
                    if(dot[j].y2 < dot[i].y1 || dot[j].y1 > dot[i].y2) continue;
                    if(dot[i].y2 < dot[j].y1 || dot[i].y1 > dot[j].y2) continue;
                }
                
                if(dot[j].y1 == dot[j].y2)
                {
                    if(dot[j].x2 < dot[i].x1 || dot[j].x1 > dot[i].x1) continue; 
                    if(dot[j].y1 < dot[i].y1 || dot[j].y1 > dot[i].y2) continue; 
                }
            }
            
            else
            {
                if(dot[j].y1 == dot[j].y2)
                {
                    if(dot[i].y1 < dot[j].y1 || dot[i].y1 > dot[j].y1) continue;
                    if(dot[j].y1 < dot[i].y1 || dot[j].y1 > dot[i].y1) continue;
                    if(dot[j].x2 < dot[i].x1 || dot[j].x1 > dot[i].x2) continue;
                    if(dot[i].x2 < dot[j].x1 || dot[i].x1 > dot[j].x2) continue;
                }
                
                if(dot[j].x1 == dot[j].x2)
                {
                    if(dot[j].y2 < dot[i].y1 || dot[j].y1 > dot[i].y1) continue; 
                    if(dot[j].x1 < dot[i].x1 || dot[j].x1 > dot[i].x2) continue; 
                }
            }
            
            return false;
        }
    }
    
    return true;
}

int main()
{
    scanf("%d", &T);
    
    while(T--)
    {
        scanf("%d", &N);
        
        for(int i = 1; i <= N; i++)
        {
            scanf("%d %d %d %d", &dot[i].x1, &dot[i].y1, &dot[i].x2, &dot[i].y2);
            
            if(dot[i].x1 > dot[i].x2) swap(dot[i].x1, dot[i].x2);
            if(dot[i].y1 > dot[i].y2) swap(dot[i].y1, dot[i].y2);
        }
        
        if(calc()) printf("SAFE\n");
        else printf("DANGEROUS\n");
    }
    
    return 0;
}