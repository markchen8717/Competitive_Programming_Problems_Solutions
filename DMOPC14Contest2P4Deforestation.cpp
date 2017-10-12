// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
int mass[1000000];
int sum[1000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> mass[i];
	}
	//Implement Prefix Sum Array
	
	sum[0] = mass[0];
	for (int i = 1; i < N; i++)
	{
		sum[i] = sum[i - 1] + mass[i];
	}
	cin >> Q;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1];
	}
	return 0;
}

