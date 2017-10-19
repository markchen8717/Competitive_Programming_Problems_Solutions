// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
long int sum(int x,vector<long int> &BIT) {
	long int output = 0;


	while (x > 0)
	{
		output += BIT[x];
		x -= x & -x;

	}
	return output;
}

void update(int x, int v, int N, vector <long int> &BIT)
{
	while (x <= N)
	{
		BIT[x] += v;
		x += x & -x;
	}
}
//New BIT
	vector<long int>NewBIT(100000 + 1, 0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M ;
	vector <long int> input(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;
		input[i] = temp;

	}
	
	//BIT
	vector<long int> BIT(N+1, 0);
	
	

	for (int i = 1; i <= N ; i++)
	{
		
			update(i, input[i], N, BIT);//BIT
			update(input[i], 1, 100000 + 1, NewBIT); //NewBIT
		
	
	}
	

	while (M--)
	{
		char q;
		int a, b;
		cin >> q;
		if (q == 'C')
		{
			cin >> a >> b;
			
			int dif = b - input[a];
				update(input[a], -1, 100000 + 1, NewBIT); //NewBIT
			update(a, dif, N, BIT);

			input[a] = b;
				update(input[a], 1, 100000 + 1, NewBIT); //NewBIT
				

			

		}
		else if (q == 'S')
		{
			cin >> a >> b;
			cout << sum(b, BIT) - sum(a - 1, BIT) << "\n";

		}
		else
		{
			cin >> a;
			cout << sum(a, NewBIT)<< "\n";
		}
	}

	
	 
	


	
	
	return 0;
}

