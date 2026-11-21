#include <iostream>
#include <vector>
using namespace std;
int main()
{
	string n,m;
	string nMin, mMin, nMax, mMax;
	cin >> n >> m;
	nMin = nMax = n;
	mMin = mMax = m;
	for (int i = 0; i < n.size(); i++) {
		if (n[i] == '6') nMin[i] = '5';
		if (n[i] == '5') nMax[i] = '6';
	}

	for (int i = 0; i < m.size(); i++) {
		if (m[i] == '6') mMin[i] = '5';
		if (m[i] == '5') mMax[i] = '6';
	}

	cout << atoi(nMin.c_str()) + atoi(mMin.c_str()) << " " << atoi(nMax.c_str()) + atoi(mMax.c_str());
}