#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int n, k;

char s[100005];

int main()
{
    scanf("%d", &t);

    while(t--){
        scanf("%d %d", &n, &k);
        scanf("%s", s);

        char ans[100005];
        int g=-1, h=-1, cnt=0;

        for(int i=0; i<n; i++) ans[i] = '.';

        for(int i=0; i<n; i++){
            if(s[i] == 'G'){
                if(g >= i) continue;
                else{
                    if(i+k > n-1){
                        for(int j=n-1; j>=i-k; j--){
                            if(ans[j] == '.'){
                                ans[j] = 'G';
                                break;
                            }
                        }
                    }
                    else ans[i+k] = 'G';
                    g = i+k+k;
                    cnt++;
                }
            }

            else{
                if(h >= i) continue;
                else{
                    if(i + k > n-1){
                        for(int j=n-1; j>=i-k; j--){
                            if(ans[j] == '.'){
                                ans[j] = 'H';
                                break;
                            }
                        }
                    }
                    else ans[i+k] = 'H';
                    h = i+k+k;
                    cnt++;
                }
            }
        }

        printf("%d\n", cnt);
        for(int i=0; i<n; i++){
            printf("%c", ans[i]);
        }

        printf("\n");
    }


    return 0;
}