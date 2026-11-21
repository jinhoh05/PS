#include<bits/stdc++.h>

using namespace std;
/*
    cin 쓰고 싶을때
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
*/
/// 왜 scanf 쓰니까 잘 안되는지 모르겠다

int n, m, rem;
int word[10005];
string s;

void init(){
    char a = 'a';
	for(int i=0;i<26;i++){
        rem |= 1 << (a - 'a');
        a++;
	}
}

void bitmask(){
    for(int i=0;i<m;i++){
        int o, ans = 0;
        char x;
        cin >> o >> x;

		if(o == 1) rem &= ~(1 << (x - 'a'));
		else rem |= 1 << (x - 'a');

		for(int i=0;i<n;i++){
			if((rem & word[i]) == word[i]) ans++;
		}

        cout << ans << "\n";
    }
}

void input(){
    cin >> n >> m;

	for(int i=0;i<n;i++){
		cin >> s;

		for(char c : s){
			word[i] |= 1 << (c - 'a');
		}
	}
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    input();

    init();

    bitmask();

	return 0;
}
