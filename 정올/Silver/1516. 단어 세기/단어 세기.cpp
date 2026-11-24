#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    char s[35][202];
    char st[202];
    char c[202];
    int len;
    int x=0,y=0;
    int cnt=1;
    for(int i=0;i<30;i++){
        fgets(st,202,stdin);
        len=strlen(st);

        while (st[len-1] == '\n' || st[len-1] == '\r')
                st[--len] = '\0';

        if(strcmp(st,"END") == 0){
            return 0;
        }


        for(int j=0;j<len;j++){
            if(st[j] == ' '){
                s[x][y]='\0';
                x++;
                y=0;
            }
            else{
                s[x][y]=st[j];
                y++;
            }
        }
        s[x][y]='\0';
        x++;

        for(int k=0;k<x-1;k++){
            for(int h=k+1;h<x;h++){
                if(strcmp(s[k],s[h])>0){
                    strcpy(c,s[k]);
                    strcpy(s[k],s[h]);
                    strcpy(s[h],c);
                }
            }
        }
        s[x][y]='\0'; x++;
        /*for(int k=0;k<x;k++){
            printf("%s\n",s[k]);
        }*/

        for(int k=0;k<x-1;k++){
            if(strcmp(s[k],s[k+1])==0){
                cnt++;
            }
            else{
                printf("%s : %d\n",s[k],cnt);
                cnt=1;
            }

        }

        x=y=0;

    }
    return 0;
}