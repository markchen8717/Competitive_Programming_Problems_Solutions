// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int length[2004] = { 0 };
	int sums[4004] = { 0 };

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		length[a]++;
	}
	for (int i = 1; i <= 2000; i++)
	{
		if (length[i])
		{
			for (int j = i; j <= 2000; j++)
			{
				if (j == i)
					sums[i + j] += length[i] / 2;
				else if (length[j])
					sums[i + j] += min(length[i], length[j]);
			}
		}
	}
	int ans1 = 0;
	int ans2 = 1;
	for (int i = 1; i <= 4000; i++)
	{
		if (sums[i] > ans1)
		{
			ans1 = sums[i];
			ans2 = 1;
		}
		else if (sums[i] == ans1)
		{
			ans2++;
		}
	}
	cout << ans1 << " " << ans2;

	return 0;
}

