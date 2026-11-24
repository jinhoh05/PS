#include <bits/stdc++.h>

using namespace std;

int main()
{
    string stick;

    cin >> stick;

    int a[10002]={0};
    int cnt=0;
    int sum=0;
    int max=0;
    for(int i=0;i<stick.size();i++){
        if(stick[i] == '('){
            cnt++;
            if(stick[i+1] == ')'){
                cnt--;
                i++;
                max+=cnt;
            }
        }

        else if(stick[i] == ')'){
            max++;
            cnt--;
        }
    }
    printf("%d",max);







    return 0;
}