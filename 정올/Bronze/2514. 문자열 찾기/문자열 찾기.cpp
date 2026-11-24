#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int m=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'K' && s[i+1] == 'O' && s[i+2] == 'I')
        m++;
    }
    cout << m << '\n';
    m=0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I')
        m++;
    }
    cout << m;
    m=0;

    return 0;
}