#include <bits/stdc++.h>
#include "combo.h"

using namespace std;

string S;

string guess_sequence(int N) {
    if(press("XY")){
        if(press("X")) S += 'X';
        else S += 'Y';
    }
    else{
        if(press("A")) S += 'A';
        else S += 'B';
    }

    vector<char> v;
    for(auto c : string("XYAB")){
        if(S[0] != c) v.push_back(c);
    }

    auto check = [&v](){
        string s;
        s.append(S); s.append(1, v[0]); s.append(1, v[0]);
        s.append(S); s.append(1, v[0]); s.append(1, v[1]);
        s.append(S); s.append(1, v[0]); s.append(1, v[2]);
        s.append(S); s.append(1, v[1]);
        return press(s);
    };

    for(int i=1; i<N-1; i++){
        S += v[2 - (check() - i)];
    }

    if(N > 1){
        if(press(S + v[0]) == N) S += v[0];
        else if(press(S + v[1]) == N) S += v[1];
        else S += v[2];
    }

    return S;
}
