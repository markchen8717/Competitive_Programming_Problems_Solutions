// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector <int> tides(N, 0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		tides[i] = a;
	}

	sort(tides.begin(), tides.end());
	int j = ceil(N / 2.0);
	for (int i = j - 1; i >= 0; i--)
	{
		cout << tides[i] << " ";
		if (j < N)
		{
			cout << tides[j] << " ";
			j++;
		}
	}
	return 0;
}