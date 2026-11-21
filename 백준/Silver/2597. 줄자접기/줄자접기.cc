#include <bits/stdc++.h>

using namespace std;
int color[4][3];
int cnt=1;
double len,n;

int main()
{
    scanf("%lf",&n);

    for(int i=1;i<=3;i++){
        scanf("%d %d",&color[i][1],&color[i][2]);
    }

    for(int i=1;i<=3;i++){
        if(color[i][1] != color[i][2]){
            len=(double)(color[i][1] + color[i][2]) / 2.0;

            for(int j=i+1;j<=3;j++){
                for(int k=1;k<=2;k++){
                    if(len < n - len){
                        if(color[j][k] > len) color[j][k]=n - color[j][k];
                        else color[j][k]+=(n - len - len);
                    }
                    else{
                        if(color[j][k] > len) color[j][k]=len - (color[j][k] - len);
                    }
                }
            }

            if(len < n - len) n-=len;
            else n=len;
        }
    }

    printf("%0.1f",n);

    return 0;
}