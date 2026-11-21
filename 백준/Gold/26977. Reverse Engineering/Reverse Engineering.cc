#include <bits/stdc++.h>

using namespace std;

int t;
int n, k, ans[105];

char b[105][105];

int main()
{
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);

        for(int i=0; i<k; i++){
            for(int j=0; j<n; j++){
                scanf(" %c", &b[i][j]);
            }
            scanf("%d", &ans[i]);
        }

        int ck[105]={0};
        while(1){
            int c[105][3];
            for(int i=0; i<100; i++)
                for(int j=0; j<2; j++)
                    c[i][j] = -2;

            for(int i=0; i<n; i++){
                for(int j=0; j<k; j++){
                    if(ck[j]) continue;

                    if(b[j][i] == '0'){
                        if(c[i][0] == -2) c[i][0] = ans[j];
                        else if(c[i][0] != ans[j]) c[i][0] = -1;
                    }

                    else{
                        if(c[i][1] == -2) c[i][1] = ans[j];
                        else if(c[i][1] != ans[j]) c[i][1] = -1;
                    }
                }
            }

            int p=-1, q=-1;
            for(int i=0; i<2; i++){
                for(int j=0; j<n; j++){
                    if(c[j][i] == 1 || c[j][i] == 0){
                        p=i, q=j;
                    }
                }
            }

            bool flag = true;
            if(p == -1){
                int o=-1;
                for(int i=0; i<k; i++){
                    if(ck[i] == 0){
                        if(o==-1) o=ans[i];
                        else if(o != ans[i]){
                            printf("LIE\n");
                            flag = false;
                            break;
                        }
                    }
                }

                if(flag == true) printf("OK\n");
                break;
            }

            else{
                for(int i=0;i<k;i++){
                    if(b[i][q] == '0' + p) ck[i]=1;
                }
            }

            int cn=0;
            for(int i=0; i<k; i++){
                if(ck[i] == 1) cn++;
            }
            if(cn == k){
                printf("OK\n");
                break;
            }
        }

    }

    return 0;
}
