#include <bits/stdc++.h>

using namespace std;

int n, p, l, ans, cnt;

vector<string> s;
set<string> word;

int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i=0; i<4; i++){
        string a;
        cin >> a;
        s.push_back(a);
    }
    
    for(int k=0; k<24; k++){
        next_permutation(s.begin(), s.end());
        string a = "";
        
        for(int i=0; i<6; i++){
            a += s[0][i];
            word.insert(a);
            
            for(int j=0; j<6; j++){
                a += s[1][j];
                word.insert(a);
                
                for(int l=0; l<6; l++){
                    a += s[2][l];
                    word.insert(a);
                    
                    for(int r=0; r<6; r++){
                        a += s[3][r];
                        word.insert(a);
                        a.pop_back();
                    }
                    a.pop_back();
                }
                a.pop_back();
            }
            a.pop_back();
        }
    }
    
    while(n--){
        string a;
        cin >> a;
        if(word.count(a)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}