/*
DMOPC '14 Contest 2 P4 - Deforestation

https://dmoj.ca/problem/dmopc14c2p4

The Logging Company has a long line of NN (1≤N≤1000000)(1≤N≤1000000) trees numbered from 00 to N−1N−1. Each tree ii has a mass mimi (0≤mi≤2000)(0≤mi≤2000). The Company wants to cut some of the trees, so they hired you to calculate the mass of all the wood they would get from cutting all the trees between positions aa and bb inclusive (0≤a,b<N)(0≤a,b<N). In particular, they want you to answer QQ (1≤Q≤1000000)(1≤Q≤1000000) such queries.

Input Specification

First line: NN.
Lines 22 to N+1N+1: line i+2i+2 is the mass of tree ii, mimi.
The line N+2N+2 will contain the integer QQ, the number of queries the logging company wants answered.
The next QQ lines will contain the integers aa and bb.
Output Specification

For each query, print the total mass of the trees at position ii such that a≤i≤ba≤i≤b.

Scoring

For 30% of the points, N,Q≤1000N,Q≤1000.
For 50% of the points, N,Q≤10000N,Q≤10000.
For the rest, N,Q≤1000000N,Q≤1000000.
Sample Input

Copy
5
1
2
3
4
5
3
0 4
1 3
2 2
Sample Output

Copy
15
9
3

*/

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

