#include <bits/stdc++.h>

using namespace std;

int A, B, sum;
int a[15], b[15];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=10;i++) cin >> a[i];
    for(int i=1;i<=10;i++) cin >> b[i];

    for(int i=1;i<=10;i++){
        if(a[i] > b[i]){
            A += 3;
            sum = 1;
        }

        else if(a[i] < b[i]){
            B += 3;
            sum = 2;
        }

        else{
            A += 1;
            B += 1;
        }
    }

    if(A > B) cout << A << " " << B << "\n" << 'A';
    else if(A < B) cout << A << " " << B << "\n" << 'B';
    else{
        if(!sum) cout << A << " " << B << "\n" << 'D';
        else if(sum == 1) cout << A << " " << B << "\n" << 'A';
        else cout << A << " " << B << "\n" << 'B';
    }

    return 0;
}
