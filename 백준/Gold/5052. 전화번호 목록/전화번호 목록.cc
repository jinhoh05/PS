#include <bits/stdc++.h>

using namespace std;

int t;

char s[10005][11];

vector<string> v;

struct Trie
{
    bool finish;
    Trie *Node[10];

    Trie()
    {
        finish = false;
        for (int i = 0; i < 10; i++) Node[i] = NULL;
    }

    void Insert(char *str)
    {
        if(*str == NULL)
        {
            finish = true;
            return;
        }

        int cur = *str - '0';
        if (Node[cur] == NULL) Node[cur] = new Trie();
        Node[cur]->Insert(str + 1);
    }

    bool Find(char *str)
    {
        if(*str == NULL) return false;

        if(finish == true) return true;

        int cur = *str - '0';
        if (Node[cur] == NULL) return false;
        return Node[cur]->Find(str + 1);
    }
};

int main()
{
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        string st;

        Trie *root = new Trie();

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            v.push_back(s[i]);
            root->Insert(s[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (root->Find(s[i]))
            {
                cout << "NO\n";
                break;
            }

            else if(i == n - 1)
            {
                cout << "YES\n";
            }
        }
    }

    return 0;
}
