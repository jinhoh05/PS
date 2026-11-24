#include <bits/stdc++.h>

using namespace std;

int t;
int s1_st, s1_fin, s2_st, s2_fin;

int alpha1[30][200005], alpha2[30][200005];
int s1_l[200005], s1_r[200005];
int s2_l[200005], s2_r[200005];

string s1, s2, same;

vector<int> v1, v2;

void prefix()
{
    for(char i = 'a'; i <= 'z'; i++)
    {
        for(int j = 1; j < s1.size(); j++)
        {
            alpha1[i - 97][j] = alpha1[i - 97][j - 1];
            if(s1[j] == i) alpha1[i - 97][j]++;
        }

        for(int j = 1; j < s2.size(); j++)
        {
            alpha2[i - 97][j] = alpha2[i - 97][j - 1];
            if(s2[j] == i) alpha2[i - 97][j]++;
        }
    }
}

void find_len()
{
    int cnt = 1;
    for(int i = 1; i < s1.size(); i++)
    {
        if(s1[i] == same[cnt])
        {
            s1_l[cnt++] = i;
        }
    }

    cnt = same.size() - 1;

    for(int i = s1.size() - 1; i >= 1; i--)
    {
        if(s1[i] == same[cnt])
        {
            s1_r[cnt--] = i;
        }
    }

    cnt = 1;

    for(int i = 1; i < s2.size(); i++)
    {
        if(s2[i] == same[cnt])
        {
            s2_l[cnt++] = i;
        }
    }

    cnt = same.size() - 1;

    for(int i = s2.size() - 1; i >= 1; i--)
    {
        if(s2[i] == same[cnt])
        {
            s2_r[cnt--] = i;
        }
    }

    s1_r[same.size()] = s1.size();
    s2_r[same.size()] = s2.size();
}

bool find_same()
{
    bool flag1, flag2;
    for(int i = 0; i < 26; i++)
    {
        flag1 = false, flag2 = false;

        if(alpha1[i][s1_fin] - alpha1[i][s1_st] > 0) flag1 = true;
        if(alpha2[i][s2_fin] - alpha2[i][s2_st] > 0) flag2 = true;

        if(flag1 && flag2) return true;
    }

    return false;
}

int main()
{
    cin.tie()->ios_base::sync_with_stdio();

    cin >> t;

    while(t--)
    {
        cin >> s1 >> s2;
        cin >> same;

        s1 = '0' + s1;
        s2 = '0' + s2;
        same = '0' + same;

        prefix();

        find_len();

        bool flag = false;
        for(int i = 1; i <= same.size(); i++)
        {
            s1_st = s1_l[i - 1];
            s2_st = s2_l[i - 1];

            s1_fin = s1_r[i] - 1;
            s2_fin = s2_r[i] - 1;

            if(find_same())
            {
                flag = true;
                break;
            }
        }

        if(flag) cout << "1\n";
        else cout << "0\n";

        memset(s1_l, 0, sizeof(s1_l));
        memset(s1_r, 0, sizeof(s1_r));
        memset(s2_l, 0, sizeof(s2_l));
        memset(s2_r, 0, sizeof(s2_r));
        memset(alpha1, 0, sizeof(alpha1));
        memset(alpha2, 0, sizeof(alpha2));

        /*
        for(int i = 0; i < same.size(); i++) cout << s1_l[i] << " ";
        cout << " ";
        for(int i = 0; i < same.size(); i++) cout << s1_r[i] << " ";

        cout << "\n";

        for(int i = 0; i < same.size(); i++) cout << s2_l[i] << " ";
        cout << " ";
        for(int i = 0; i < same.size(); i++) cout << s2_r[i] << " ";
        */
    }

    return 0;
}


