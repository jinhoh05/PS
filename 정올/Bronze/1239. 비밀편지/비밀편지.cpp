#include <bits/stdc++.h>
using namespace std;

#define A "000000"
#define B "001111"
#define C "010011"
#define D "011100"
#define E "100110"
#define F "101001"
#define G "110101"
#define H "111010"

int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    string str, res;
    string match[8]={A,B,C,D,E,F,G,H};

    cin >> n;
    cin >> str;

    int pos = 0;
    for (int i=0;i<n;i++){
        string word = str.substr(pos, 6);

        if(A == word) res += "A";
        else if(B == word) res += "B";
        else if(C == word) res += "C";
        else if(D == word) res += "D";
        else if(E == word) res += "E";
        else if(F == word) res += "F";
        else if(G == word) res += "G";
        else if(H == word) res += "H";
        else{
            bool Match = false;
            int isMatCount;
            for (int j=0;j<8;j++){
                isMatCount = 0;
                for (int idx=0;idx<6;idx++){
                    if ((word[idx] == match[j][idx]) != 1) isMatCount++;
                }
                if(isMatCount <= 1){
                    res += 'A' + j;
                    Match = true;
                    break;
                }
            }

            if(!Match){
                cout << i + 1 << endl;
                return 0;
            }
        }
        pos += 6;
    }

    cout << res;

    return 0;
}