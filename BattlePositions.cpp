// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int guards[100000];
	int station[100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int I, N, J;
	cin >> I>>N>>J;
	
	while (J--) {
		int a, b,k;
		cin >> a >> b >> k;
		station[a] += k;
		if(b != 100000)
			station[b + 1] -= k;
	}
	guards[1] = station[1];
	for (int i = 2; i <= I; i++)
	{
		guards[i] = guards[i - 1] + station[i];
	}
	int counter = 0;
	for (int i = 1; i <= I; i++) {
		if (guards[i] < N)
			counter++;
	}
	
	cout << counter;

	return 0;
}

