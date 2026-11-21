#include <bits/stdc++.h>
 
using namespace std;
char cube[5][7],code[18],ans[10000][18];
int pattern[6][6]={{4,5,0,1,2,3},{5,4,0,3,2,1},{0,2,1,4,3,5},{2,0,1,5,3,4},{1,3,0,5,2,4},{3,1,0,4,2,5}};
int m;
void up(){
    for(int i=0;i<4;i++){
        swap(code[i*4+0],code[i*4+1]);
        swap(code[i*4+1],code[i*4+2]);
        swap(code[i*4+2],code[i*4+3]);
    }
}
 
void check(){
 
    int same=0,sw;
 
    for(int i=0;i<4;i++){
        if(same == 0){
            for(int j=0;j<m;j++){
                sw = 0;
                for(int k=0;k<17;k++){
                    if(code[k] != ans[j][k]) sw = 1;
                }
                if(sw == 0) same = 1;
            }
        }
        up();
    }
 
    if(same == 0){
        for(int i=0;i<17;i++){
            ans[m][i]=code[i];
        }
        m++;
    }
 
}
 
void dfs(int p){
    for(int i=0;i<4;i++){
        for(int j=0;j<p-1;j++){
            if(code[(p-1)*4+i] == code[j*4+i]) return;
        }
    }
 
    if(p == 4) check();
 
    else{
        for(int i=0;i<6;i++){
            for(int j=0;j<4;j++){
 
                for(int k=0;k<4;k++){
                    code[p*4+k]=cube[p][pattern[i][2+(j+k)%4]];
                }
 
                if(p == 3) code[16] = cube[p][pattern[i][0]];
                dfs(p + 1);
                if(cube[p][2] == cube[p][3] && cube[p][3] == cube[p][4] && cube[p][4] == cube[p][5]) break;
                if(cube[p][2] == cube[p][4] && cube[p][3] == cube[p][5] && cube[p][2] != cube[p][3] && j == 1) break;
            }
        }
    }
}
 
int main()
{
    for(int i = 0;i<4;i++){
        scanf("%s",cube[i]);
    }
 
    dfs(0);
 
    printf("%d",m);
    return 0;
}