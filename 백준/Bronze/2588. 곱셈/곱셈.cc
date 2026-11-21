/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    
    cin >> a >> b;
    
    c = a * b;
    
    while(b > 0)
    {
        cout << a * (b % 10) << "\n";
        b /= 10;
    }
    
    cout << c;    
        
    return 0;
}
