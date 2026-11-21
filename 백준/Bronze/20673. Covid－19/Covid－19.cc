#include <bits/stdc++.h>  
using namespace std;
int main() 
{ 
    cin.tie(NULL); 
    ios::sync_with_stdio(false); 
    int32_t avgNumNewCasesPerDay; 
    cin >> avgNumNewCasesPerDay; 
    int32_t avgNumNewHospitalizationsPerDay; 
    cin >> avgNumNewHospitalizationsPerDay; 
    string colorResult = ""; 
    if ((avgNumNewCasesPerDay <= 50) && (avgNumNewHospitalizationsPerDay <= 10)) 
    { 
        colorResult = "White"; 
    } 
    else if (avgNumNewHospitalizationsPerDay > 30) 
    { 
        colorResult = "Red"; 
    } 
    else 
    { 
        colorResult = "Yellow"; 
    } 
    cout << colorResult; 
    return 0;
}
