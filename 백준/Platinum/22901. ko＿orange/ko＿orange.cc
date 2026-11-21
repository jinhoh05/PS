#include <iostream>

#include <vector>

#include <algorithm>

#define mid (l+r)/2

using namespace std;

struct S {

    int l, r, d;

};

vector<S> V;

int ck[3000];

int dp[3000];

int ask(int x) {

    if (ck[x] >= 2) return dp[x];

    int ret;

    ck[x]++;

    cout << "? " << x << "\n";

    std::cout.flush();

    cin >> ret;

    if (ck[x] == 2) dp[x] = ret; // 2번째 질문이면 무조건 지금 답변은 거짓말이 아니다

    return ret;

}

int main()

{

    int T;

    cin >> T;

    while (T--) {

        int l = 2100, r = 2399, lie = 0;

        for (int i = 2100; i <= 2400; i++) {

            ck[i] = 0;

            dp[i] = 0;

        }

        V.clear();

 

        while (1) {

            if (!(l + 1 < r)) {//while문이 다음번에 끝날 예정이다.

                int tmp = 1;

                if (l != r) // 이므로 l인지, l+1(r) 인지 검사해 준다. (l+1 이 1이면 l+1)

                    tmp = ask(r);

                // 미친새끼가 마지막에 구라를 칠수가 있다.

                if (!lie && tmp == 0 && V.back().d == 1) { // 마지막이 0이라면 전에 구라를 쳤던거일 가능성이 있다. 방금전거 물어본다

                    //printf("IT CAN BE LIE");

                    int tmp2 = ask((V.back().l + V.back().r) / 2); // 질문

                    if (tmp2 == 0) { // up이 사실 거짓이였다.

                        //printf("AM I RIGHT");

                        l = V.back().l;

                        r = (V.back().l + V.back().r) / 2 - 1;

                        V.pop_back(); // 거짓이였던 값을 pop 해준다

                        V.push_back({ l,r,tmp2 }); // 새로 만든 범위를 push 해준다

                        lie = 1;

                        continue;

                    }

                }

                else if (!lie && tmp) tmp = ask(r);

 

                if (tmp == 1) cout << "! " << r << '\n';

                else cout << "! " << l << '\n';

                cout.flush();

                break;

            }// 종료조건 끝

            //printf("%d %d %d\n", l, r,lie);

            int ans = ask(mid);

            if (!lie && !V.empty() && ans == 0 && V.back().d == 1) { // 거짓말을 한 적이 없으면서 , 마지막 답변이 up, 지금 down

                //printf("UP DOWN CK");

                int tmp = ask((V.back().l + V.back().r) / 2); // up이 거짓일 수 있으니 한번 다시 물어본다

                if (tmp == 0) { // up이 사실 거짓이였다.

                    //printf("IT WAS FALSE");

                    l = V.back().l; 

                    r = (V.back().l + V.back().r) / 2 - 1;

                    V.pop_back(); // 거짓이였던 값을 pop 해준다

                    V.push_back({ l,r,tmp }); // 새로 만든 범위를 push 해준다

                    lie = 1;

                    continue;

                }

            }// 저번게 거짓이 아니였으면 이번답변으로 탐색을 한다.

            V.push_back({ l,r,ans });

            if (ans) l = mid; //ans가 up.

            else r = mid - 1; // ans가 down

        } 

       // while문 끝

    }

    return 0;

}