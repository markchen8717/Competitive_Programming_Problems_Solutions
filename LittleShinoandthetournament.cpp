// Implementation
//


#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n;
	cin >> q;

	int strengths[100031];
	int life[100031];
	int fights[100031];

	for (int i = 1; i <= n; i++)
	{
		cin >> strengths[i];
		life[i] = 1;
		fights[i] = 0;
	}
	int j = 1;
	int k = 1;
	int fight_num = n;
	while (fight_num)
	{
		j = 1;

		while (j <= n)
		{
			if (life[j] == 1)
			{
				k = j + 1;
				while (k <= n)
				{
					if (life[k] == 1)
					{
						fights[j]++;
						fights[k]++;
						if (strengths[j] > strengths[k])
						{
							life[k] = 0;
						}
						else
						{
							life[j] = 0;
						}
						j = k;
						break;
					}
					k++;
				}
			}
			j++;
		}
		fight_num /= 2;
	}



	while (q--) {
		int a;
		cin >> a;
		cout << fights[a] << "\n";
	}





	return 0;
}

