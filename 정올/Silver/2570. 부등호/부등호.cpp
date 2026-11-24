#include <bits/stdc++.h>

using namespace std;
int k, num, j, see;
char s[10], small[10], big[10];

void path_big(int number_now, int char_now){
    if(s[char_now] == '>' || char_now == k){
        big[number_now] = j + '0';
        see = number_now + 1;
        j--;
        return;
    }

    else path_big(number_now + 1, char_now + 1);
    big[number_now] = j + '0';
    j--;
}

void path_small(int number_now, int char_now){
    if(s[char_now] == '<' || char_now == k){
        small[number_now] = j + '0';
        see = number_now + 1;
        j++;
        return;
    }

    else path_small(number_now + 1, char_now + 1);
    small[number_now] = j + '0';
    j++;
}

void seq(int i){
    if(i == 1){
        int number_now = 0, char_now = 0;
        j = 9;
        while(see <= k){
            path_big(number_now, char_now);
            number_now = char_now = see;
        }
        cout << big << '\n';
    }

    else{
        int number_now = 0, char_now = 0;
        j = see = 0;
        while(see <= k){
            path_small(number_now, char_now);
            number_now = char_now = see;
        }
        cout << small;
    }
}

int main()
{
    scanf("%d", &k);
    for(int i=0;i<k;i++) scanf(" %c", &s[i]);

    for(int i=1;i<=2;i++) seq(i);

    return 0;
}