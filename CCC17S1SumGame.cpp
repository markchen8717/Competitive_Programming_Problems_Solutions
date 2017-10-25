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
	vector <int> swifts(N + 1, 0);
	vector <int> semp(N + 1, 0);
	
		int a;
		cin >> a;
		swifts[1] = a;
		for (int j = 2; j <= N; j++)
		{
			
			cin >> a;
			swifts[j] = swifts[j - 1] + a;
		}

	
		cin >> a;
		semp[1] = a;
		for (int j = 2; j <= N; j++)
		{

			cin >> a;
			semp[j] = semp[j - 1] + a;
		}
		int output = 0;
		for (int i = 1; i <= N; i++)
		{
			if (semp[i] == swifts[i])
			{
				output = i;
				
			}

		}
		cout << output;

	
}

