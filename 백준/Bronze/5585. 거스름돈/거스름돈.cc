#include <bits/stdc++.h>

using namespace std;

int pay;
int coin[10]={500,100,50,10,5,1};

int Coin()
{ 
    int total = 1000 - pay;
    int cnt = 0;

    for(int i=0; i<6; i++){
        while(total - coin[i] >= 0){
            total -= coin[i];
            cnt++;
            if(total == 0) break;
        }
    }
    
    return cnt;
} 

int main()
{
    cin >> pay;
    cout << Coin();
    
    return 0;
}