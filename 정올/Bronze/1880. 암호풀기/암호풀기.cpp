#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

int main()
{
    char s1[81];
    char s[30];

    fgets(s,30,stdin);
    fgets(s1,81,stdin);

    int mx=0;
    char xm;
    for(int i=0;i < strlen(s1);i++){
        if(s1[i] >= 'a'){
            mx=s1[i] - 'a';
            printf("%c",s[mx]);
        }

        else if(s1[i] >= 'A'){
            mx=s1[i] - 'A';
            printf("%c",s[mx] - 32);
        }

        else{
            printf(" ");
        }
    }



    return 0;
}