#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int m=10;
    for(int i=1;i<s.size();i++){
        if(s[i] == s[i-1]){
            m+=5;
        }
        else m+=10;
    }
    cout << m;

    return 0;
}