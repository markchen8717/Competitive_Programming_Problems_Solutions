/*

Lamppost

https://dmoj.ca/problem/hci16lamppost

Task Description

You are an electrician working in Moonlight City. One night, the city council gave you a call and informed you that the lampposts in Moonlight Square are all out of order, so they need your help. Moonlight Square is divided into NN zones, each of which contains a single lamppost. When you arrived in Moonlight Square, you realised that you only have one light bulb in your toolbox, and so you can only repair one lamp. The lampposts are numbered 11 to NN and each lamppost can light up a certain number of zones around it. Decide which lamppost to repair so that the most number of zones will be lit.

Input

The first line consists of two integers, NN and CC. The next CC lines contain two integers each, C1C1 and C2C2, indicating that C1C1 can be lit from C2C2 and vice versa.

Output

Output the index of the lamppost which, when repaired, will light up the largest number of zones in the Square. Ties are broken by choosing the lamppost with the numerically largest index.

Limits

For all test cases, 1≤N≤1000000,1≤C≤10000001≤N≤1000000,1≤C≤1000000

Subtask 1 (20%): 1≤N<1000,1≤C<10001≤N<1000,1≤C<1000

Subtask 2 (80%): 1000≤N≤1000000,1000≤C≤10000001000≤N≤1000000,1000≤C≤1000000

Sample Input

Copy
10 5
1 2
1 3
1 4
1 5
2 6
Sample Output

Copy
1


*/

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

