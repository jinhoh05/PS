#include <bits/stdc++.h>

using namespace std;
string a, b;
int divide[205], i, p, x, len_a, len_b;

int solve(int X, int len_B){
    int carry = 0, ret = 0;

    while(1){
        X = x-len_b;
        len_B = 0;
        while(1){
            if(len_B == 0 && X != 0 && a[X - 1] != '0') break;
            else if(a[X] < b[len_B]) return ret;
            else if(a[X] > b[len_B]) break;
            else if(a[X] == b[len_B]){
                X++;
                len_B++;
                continue;
            }
        }

        len_B = len_b-1;
        X = x-1;
        carry = 0;

        while(len_B>=0){
            a[X] = a[X] - b[len_B] - carry + '0';
            carry = 0;
            if(a[X] < '0'){
                if(X == x - len_b && a[x-len_b-1] != '0') a[x-len_b-1]--;
                carry++;
                a[X] += 10;
            }
            X--, len_B--;
        }

        ret++;
    }

    return ret;
}

void large(){
    if(a.size() < b.size()) swap(a, b);
    else if(a.size() == b.size()){
        if(a == b) printf("1");
        else if(a < b) swap(a, b);
    }
}

int main()
{
    while(1){
        cin >> a >> b;
        if(a[0] == '0' || b[0] == '0') return 0;

        large();
        len_a=a.size(), len_b=b.size(), i=0, p=0, x=len_b;

        while(x <= len_a){
            divide[i] = solve(x, len_b);
            x++,i++;
        }

        for(p=0;p<i;p++){
            if(divide[p] == 0) continue;
            else break;
        }

        int j=p;
        if(divide[p] == 0) p++;

        for(int j=p;j<i;j++) cout << divide[j];

        cout << "\n";
    }

    return 0;
}