/*

Binary Indexed Tree Test

https://dmoj.ca/problem/ds1

Xyene is doing a contest. He comes across the following problem:

You have an array of NN (1≤N≤100000)(1≤N≤100000) elements, indexed from 11 to NN. There are MM (1≤M≤500000)(1≤M≤500000) operations you need to perform on it.

Each operation is one of the following:

C x v Change the xx-th of the array to vv.
S l r Output the sum of all the elements from the ll-th to the rr-th index, inclusive.
Q v Output how many elements are less than or equal to vv in the array.
At any time, every element in the array is between 11 and 100000100000 (inclusive).

Xyene knows that one fast solution uses a Binary Indexed Tree. He practices that data structure every day, but still somehow manages to get it wrong. Will you show him a working example?

Input Specification

The first line has NN and MM.

The second line has NN integers, the original array.

The next MM lines each contain an operation in the format described above.

Output Specification

For each S or Q operation, output the answer on its own line. Note that you may need to use 64-bit integers to store the answer.

Sample Input

Copy
10 10
4 8 4 5 6 3 2 2 8 1
C 7 6
Q 7
S 2 3
S 1 4
C 4 9
S 2 3
Q 6
C 3 9
S 6 7
Q 6
Sample Output

Copy
8
12
21
12
7
9
6


*/

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

