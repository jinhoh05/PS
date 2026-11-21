#include <bits/stdc++.h>

using namespace std;

int n, m, k, now;
deque<int> dq;
vector<int> v;

void end_push(){
    if(now){
        v.push_back(dq.front());
        dq.pop_front();
    }

    else{
        v.push_back(dq.back());
        dq.pop_back();
    }
}

void push(){
    if(now){
        dq.push_back(dq.front());
        dq.pop_front();
    }

    else{
        dq.push_front(dq.back());
        dq.pop_back();
    }
}

void yose(){
    for(int i=0;i<n;i++) {
		if(i % k == 0) now ^= 1;

		for(int i=0;i<m-1;i++) push();

		end_push();
	}
}

int main(){

    scanf("%d %d %d", &n, &m, &k);

	for(int i=1;i<=n;i++) dq.push_back(i);

    yose();

	for(int u : v) printf("%d\n", u);

	return 0;
}
