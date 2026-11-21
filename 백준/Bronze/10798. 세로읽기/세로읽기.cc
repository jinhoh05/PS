#include <bits/stdc++.h>

using namespace std;

string word[5];

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    for(int i = 0; i < 5; i++) cin >> word[i];

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 5; j++){
            if(i < word[j].size()) cout << word[j][i];
        }
    }

    return 0;
}
