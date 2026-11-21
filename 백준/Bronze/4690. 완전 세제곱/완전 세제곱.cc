#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 2; i <= 100; i++)
	{
		for (int b = 2; b <= 100; b++)
		{
			for (int c = b + 1; c <= 100; c++)
			{
				for (int d = c + 1; d <= 100; d++)
				{
					if (i * i * i == b * b * b + c * c * c + d * d * d)
					{
						cout << "Cube = " << i << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
					}
				}
			}
		}
	}
    
    return 0;
}