#include <bits/stdc++.h>

using namespace std;
vector <int>c;
int a,b;

int gcd(int x,int y){
    if(y == 0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}

int main(){

    scanf("%d %d",&a,&b);

    for(int i = 1;i <= sqrt(b);i++){
        if(b%i == 0){
            if(i%a == 0){
                c.push_back(i);
            }
            if((b / i) % a == 0){
                c.push_back(b / i);
            }
        }
    }

    sort(c.begin(),c.end());

    int mini = c[0] + c[c.size() - 1];
    int x = c [0], y = c[c.size() - 1];

    for(int i=1;i<c.size()/2;i++){
        if(gcd(c[c.size()-i-1],c[i]) == a){
            if(mini > c[i] + c[c.size() - i - 1]){
                mini = c[i] + c[c.size() - i - 1];
                x = c[i];
                y = c[c.size() - i - 1];
            }
        }
    }


    printf("%d %d", x, y);
    return 0;
}