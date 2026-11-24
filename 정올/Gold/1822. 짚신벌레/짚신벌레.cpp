#include <bits/stdc++.h>
using namespace std;

#define int long long

deque<int> baby;
int sumbaby = 0;
deque<int> adult;
int sumadult = 0;
deque<int> old;
int sumold = 0;

signed main() {
    int a, b, d, n;
    cin >> a >> b >> d >> n;
    for (int i = 0; i < a; i++) baby.push_back(0);
    for (int i = 0; i < b - a; i++) adult.push_back(0);
    for (int i = 0; i < d - b; i++) old.push_back(0);
    baby.pop_back();
    baby.push_front(1);
    sumbaby++;
    for (int i = 1; i <= n; i++) {
        int Baby = baby.back() % 1000;
        int Adult = adult.back() % 1000;
        int Old = old.back() % 1000;
        baby.pop_back();
        adult.pop_back();
        old.pop_back();
        int s = sumadult + (Baby % 1000 - Adult % 1000 + 1000) % 1000;
        baby.push_front(s);
        adult.push_front(Baby % 1000);
        old.push_front(Adult % 1000);
        sumbaby += (s - Baby % 1000 + 1000) % 1000;
        sumold += (Adult % 1000 - Old % 1000 + 1000) % 1000;
        sumadult = s;
        // cout << sumbaby << ' ' << sumadult << ' ' << sumold << '\n';
    }
    cout << (sumbaby + sumadult + sumold) % 1000;
}