// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include <bits/stdc++.h>
using namespace std;


bool good(int F[], int m, int N)
{
	for (int i = 1; i < N; i++)
	{
		if (F[i] < m)
			return false;
	}
	return true;
}





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int ans = 0;
	int F[101];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> F[i];
	}
	for (int i = 1; i <= sqrt(F[0]); i++)
	{
		int tmp_ans = 1;

		if ((F[0] % i == 0) && (good(F, i, N)))
		{
			
			for (int j = 1; j < N; j++)
			{
				tmp_ans = tmp_ans * (F[j] / i % 10007) % 10007;
			}
			
			ans += tmp_ans % 10007;
			if (F[0] / i != i)
			{
				tmp_ans = 1;

				for (int j = 1; j < N; j++)
				{
					tmp_ans = tmp_ans * (F[j] / (F[0] / i) % 10007) % 10007;
				}
				ans += tmp_ans % 10007;
			}
		}

	}






	cout << ans % 10007;



	return 0;
}

