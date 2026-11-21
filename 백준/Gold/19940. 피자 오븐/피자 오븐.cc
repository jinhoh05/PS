#include <bits/stdc++.h>

using namespace std;

int a[10];
int n, k, val;

bool chk1, chk2;

int main()
{
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		chk1 = chk2 = false;

		memset(a, 0, sizeof(a));

		scanf("%d", &k);

		while(1)
        {
            if(k == 0) break;

			if(chk1 == false && chk2 == false)
			{
				if(k >= 60 && chk1 == false && chk2 == false)
				{
					k = k - 60;
					a[1]++;
				}

				else if(chk1 == false && k >= 36)
				{
					val = 60;
					chk1 = true;
					a[1]++;
				}

				else chk2 = true;
			}

			if(chk1 == true)
			{
				if(val - k >= 10)
				{
					a[3]++;
					val = val - 10;
				}

				else
				{
					if(val - k >= 6)
					{
						a[3]++;
						a[4] = a[4] + 10 - (val - k);
						break;
					}

					else
					{
						a[5] = a[5] + val - k;
						break;
					}
				}
			}

			if(chk2 == true)
			{
				if(k >= 10)
				{
					a[2]++;
					k = k - 10;
				}

				else
				{
					if(k >= 6)
					{
						a[2]++;
						a[5] = a[5] + (10 - k);
						break;
					}

					else
					{
						a[4] = a[4] + k;
						break;
					}
				}
			}
        }

		for(int j = 1; j <= 5; j++) printf("%d ", a[j]);

		printf("\n");
	}

	return 0;
}
