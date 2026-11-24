#include <iostream>
using namespace std;

int sum[10];
int cnt = 0;

void dice(int N, int M){
    for (int i = 1; i <= 6; ++i){
        sum[cnt] = i;

        if (cnt == N - 1){
            int total = 0;
            for (int j = 0; j <= cnt; ++j)
                total += sum[j];

            if (total == M){
                for (int k = 0; k < N; ++k)
                    cout << sum[k] << " ";
                cout << endl;
            }
        }

        else{
            cnt++;
            dice(N, M);
            cnt--;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    dice(N, M);

    return 0;
}