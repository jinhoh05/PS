#include <bits/stdc++.h>
#include "art.h"

using namespace std;

//
// --- Sample implementation for the task art ---
//
// To compile this program with the sample grader, place:
//     art.h art_sample.cpp sample_grader.cpp
// in a single folder, then open the terminal in this directory (right-click onto an empty spot in the directory,
// left click on "Open in terminal") and enter e.g.:
//     g++ -std=c++17 art_sample.cpp sample_grader.cpp
// in this folder. This will create a file a.out in the current directory which you can execute from the terminal
// as ./a.out
// See task statement or sample_grader.cpp for the input specification
//
void solve(int n) {
    vector<int> order;
    for(int i=0; i<n; i++){
        vector<int> v(n);

        for(int j=0; j<n; j++){
            v[j] = (i+j)%n + 1;
        }

        order.push_back(publish(v));
    }

    vector<int> ans(n);
    for(int i=0; i<n; i++){
        ans[(order[i] - order[(i+1)%n] + n-1) / 2] = i+1;
    }

    answer(ans);
}
