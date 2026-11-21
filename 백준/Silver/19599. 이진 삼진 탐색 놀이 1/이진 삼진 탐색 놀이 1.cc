#include <bits/stdc++.h>

using namespace std;

int n, x, y, z, p;
int b[500005], t[500005], b_vt[500005], t_vt[500005];
int A[500005];

int binary_search(int val, int l, int r, int lev){
    if(val == n) return 1;
    if(l >= n || r < 0) return 0;

    int mid = (l + r) / 2;

    if(b_vt[mid] == 0){
        b_vt[mid] = 1;
        b[mid] = lev;
        val++;
    }

    else return 0;

    if(binary_search(val, l, mid - 1, lev + 1)) return 1;

    if(binary_search(val, mid + 1, r, lev + 1)) return 1;

    return 0;
}

int ternary_search(int val, int l, int r, int lev){
    if(val == n) return 1;
    if(l >= n || r < 0) return 0;

    int l_third = l + ((r - l) / 3);
    int r_third = r - ((r - l) / 3);

    int visit = 0;
    if(t_vt[l_third] == 0){
        t_vt[l_third] = 1;
        t[l_third] = lev;
        visit++;
        val++;
    }

    if(t_vt[r_third] == 0){
        t_vt[r_third] = 1;
        t[r_third] = lev + 1;
        visit++;
        val++;
    }

    if(visit != 2) return 0;

    ternary_search(val, l, l_third - 1, lev + 2);

    ternary_search(val, l_third + 1, r_third - 1, lev + 2);

    ternary_search(val, r_third + 1, r, lev + 2);

    return 0;
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) A[i] = i;

    binary_search(0, 0, n - 1, 0);
    ternary_search(0, 0, n - 1, 0);

    for(int i=0;i<n;i++){
        if(b[i] < t[i]) x++;
        else if(b[i] > t[i]) z++;
        else y++;
    }

    printf("%d\n%d\n%d", x, y, z);

    return 0;
}
