#include<iostream>
#include<string>

using namespace std;


int main()
{
	string a;
	int sum = 10;
	cin >> a;

	for (unsigned int i = 1; i < a.size(); i++)
	{
		if (a[i-1] == a[i])
		{
			sum += 5;
		}
		else if (a[i-1] != a[i])
		{
			sum += 10;
		}
	}

	cout << sum << endl;
	
    return 0;
}