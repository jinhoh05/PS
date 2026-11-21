#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m, ans;

vector<int> v;

double b, c, a1, a2;

int main(){

    scanf("%lf %lf %lf %lf", &b, &c, &a1, &a2);

    printf("%.6f", (b + sqrt(b*b + 4*c)) / 2);

    return 0;
}
