#include <cstdio>
#include <iostream>

using namespace std;

int t, n;

string temp;
string DP[1005];

int check(const char &a)
{
    if(a == '(') return 1;
    else if(a == ')') return 2;
    else if(a == '{') return 3;
    else if(a == '}') return 4;
    else if(a == '[') return 5;
    else if(a == ']') return 6;
}

bool compare(const string &a, const string &b)
{
    int l1 = a.size(), l2 = b.size();
    
    if(l1 != l2) return l1 < l2;
    
    for(int i = 0; i < min(l1, l2); i++)
    {
        if(a[i] != b[i]) return check(a[i]) < check(b[i]);
    }
    
    return false;
}

void calc(int i)
{
    if(i % 2 == 0)
    {
        temp = "(" + DP[i / 2] + ")";
        if(compare(temp, DP[i])) DP[i] = temp;
    }
    
    if(i % 3 == 0) 
    {
        temp = "{" + DP[i / 3] + "}";
        if(compare(temp, DP[i])) DP[i] = temp;
    }
    
    if(i % 5 == 0)
    {
        temp = "[" + DP[i / 5] + "]";
        if(compare(temp, DP[i])) DP[i] = temp;
    }
}

void dynamic()
{
    DP[1] = "()", DP[2] = "{}", DP[3] = "[]";
    
    for(int i = 4; i <= 1000; i++)
    {
        DP[i] = DP[1] + DP[i - 1];
        
        for(int j = 2; j < i; j++)
        {
            temp = DP[j] + DP[i - j];
            if(compare(temp, DP[i])) DP[i] = temp;
        }
        
        calc(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    dynamic();
    
    cin >> t;
    
    while(t--)
    {
        cin >> n;
        cout << DP[n] << "\n";
    }
    
    return 0;
}