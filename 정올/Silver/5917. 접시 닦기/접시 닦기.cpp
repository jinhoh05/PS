#include <bits/stdc++.h>

using namespace std;

void push(int p[], int& p_size, int q[], int& q_size){
    q[q_size++] = p[--p_size];
}

int main(){
    int n, t;
    int p[10005], a[10005], b[10005];
    int p_size, a_size=0, b_size=0;

    cin >> n >> t;

    p_size = n;
    for(int i=0; i<n; i++){
        p[i] = n - i;
    }

    for(int i=0; i<t; i++){
        int c, d;
        cin >> c >> d;

        for(int j=0; j<d; j++){
            if(c == 1) push(p, p_size, a, a_size);
            else push(a, a_size, b, b_size);   
        }
    }

    for(int i=n-1; i>=0; i--){
        cout << b[i] << endl;
    }

    return 0;
}