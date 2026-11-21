#include <bits/stdc++.h>

using namespace std;

int n;
int inorder[100005];
int postorder[100005];
int tree[100005];

void query(int s, int e, int fs, int fe){
    if(s > e || fs > fe) return;

    int root = postorder[fe];
    cout << root << " ";

    int p = tree[root];
    int l = p - s;

    query(s, p - 1, fs, fs + l - 1);
    query(p + 1, e, fs + l, fe - 1);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n;

    for(int i=0;i<n;i++) cin >> inorder[i];

    for(int i=0;i<n;i++) cin >> postorder[i];

    for(int i=0;i<n;i++) tree[inorder[i]] = i;

    query(0, n - 1, 0, n - 1);

    return 0;
}
