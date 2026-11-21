#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;

vector<int> arr;

int isdeq()
{
    vector<int> fr, ba;

    for(int i = 0; i < arr.size(); i++)
    {
        bool flag = false;

        for(int j = 0; j < fr.size(); j++)
        {
            if(arr[i] < fr[j])
            {
                bool isRight = true;

                for(int k = 0; k < arr.size(); k++)
                {
                    if(arr[i] < arr[k] && arr[k] < fr[j]) isRight = false;
                }

                if(isRight)
                {
                    fr[j] = arr[i];
                    flag = true;
                    break;
                }
            }

            if(arr[i] > ba[j])
            {
                bool isRight = true;

                for(int k = 0; k < arr.size(); k++)
                {
                    if(arr[i] > arr[k] && arr[k] > ba[j]) isRight = false;
                }

                if(isRight)
                {
                    ba[j] = arr[i];
                    flag = true;
                    break;
                }
            }
        }                                                                                   

        if(!flag)
        {
            fr.push_back(arr[i]);
            ba.push_back(arr[i]);
        }
    }

    return fr.size();
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int val;
        scanf("%d", &val);

        arr.push_back(val);
    }

    printf("%d", isdeq());

    return 0;
}
