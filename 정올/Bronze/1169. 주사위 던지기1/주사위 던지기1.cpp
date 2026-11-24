#include    <iostream>
using namespace std;

int dice[5];
int cnt = 1;
void Throw(int N, int M);
int main()
{
    int N, M;
    cin >> N >> M;
    dice[0] = 1;
    Throw(N, M);

    return 0;
}

void Throw(int N, int M)
{

    if (M == 1)
    {
        for (int i = 1; i <= 6; ++i)
        {
            dice[cnt] = i;

            if (cnt == N)
            {
                for (int j = 1; j <= N; ++j)
                    cout << dice[j] << " ";
                cout << endl;
            }
            else
            {
                cnt++;
                Throw(N, M);
                cnt--;
            }
        }
    }
    else if (M == 2)
    {
        for (int i = dice[cnt - 1]; i <= 6; ++i)
        {
            dice[cnt] = i;

            if (cnt == N)
            {
                for (int j = 1; j <= N; ++j)
                    cout << dice[j] << " ";
                cout << endl;
            }
            else
            {
                cnt++;
                Throw(N, M);
                cnt--;
            }
        }
    }
    else if (M == 3)
    {
        for (int i = 1; i <= 6; ++i)
        {
            bool flg = true;
            for (int k = 1; k < cnt; ++k)
            {
                if (dice[k] == i)
                    flg = false;
            }
            if (!flg)
                continue;
            dice[cnt] = i;

            if (cnt == N)
            {
                for (int j = 1; j <= N; ++j)
                    cout << dice[j] << " ";
                cout << endl;
            }
            else
            {
                cnt++;
                Throw(N, M);
                cnt--;
            }
        }
    }
}