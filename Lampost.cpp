// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	 int N, C;
	cin >> N >> C;
	vector <vector<int>> site(N, vector< int>(0, 0));
	
	while (C--)
	{
		 int a, b;
		cin >> a >> b;
		site[a-1].push_back(b);
		site[b - 1].push_back(a);
	}
	 int z = 0;
	int index = 0;
	for ( int i = 0; i < N; i++)
	{
		if (site[i].size() >= z)
		{
			z = site[i].size();
			index = i+1;
		}
	}
	cout << index;
	return 0;
}

