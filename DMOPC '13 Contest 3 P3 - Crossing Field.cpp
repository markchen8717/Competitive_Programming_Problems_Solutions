/*
https://dmoj.ca/problem/dmopc13c3p3
You are about to cross an NN by NN meter field. However, you are not sure if it's actually possible to do so. Each square meter of the field has an elevation value — you may only cross into an adjacent square meter if the distance between the centres of the squares is equal to one and if the elevation difference between the squares is less than or equal to HH (0≤H≤1000)(0≤H≤1000).

Determine whether it is possible to cross the field or not if you start at the top left corner, square (1,1)(1,1), and end in the bottom right corner, square (N,N)(N,N).

Input Specification

The first line of input will contain 2 integers: NN and HH.

The next NN lines will contain NN integers each, the elevation of that square meter of the field. The elevation will be an integer between 00 and 10001000.

Output Specification

On a single line, output "yes" (without the quotes) if you can cross the field; otherwise, output "no" (without the quotes).

Constraints

Test Case Batch	Marks	Time Limit	Memory Limit	Constraints
1 [5 cases]	80	10 s	256 MiB	1≤N≤1001≤N≤100
2 [2 cases]	20	10 s	256 MiB	1≤N≤15001≤N≤1500
Sample Input

Copy
4 3
3 6 4 9
7 1 2 3
7 7 2 2
7 7 1 5
Sample Output

Copy
yes
Explanation for Sample Output

From the top left square, you can go right, right, down, down, right, down to reach the bottom right square.
*/
#include "stdafx.h"



#include <bits/stdc++.h>
using namespace std;

bool DFS(int N, int H,pair<int, int> vertex, vector<vector<pair<int, bool>>> &elev)
{
	
	int row = vertex.first;
	int  col = vertex.second;
	bool bool1 = false;
	bool bool2 = false;
	bool bool3 = false;
	if (row == N-1 && col == N-1)
	{
		return true;
	}
	
	//set current node as visited
	elev[row][col].second = true;


	//DFS the current node's adjacent nodes only if 
	//*they are not visited
	//*elevation difference is <= H

	int currElev = elev[row][col].first; 
	//if the bottom square meter is within map	
	if (row + 1 < N)
	{
		pair<int, bool> bottomNode = elev[row + 1][col];
		if (bottomNode.second == false && abs(bottomNode.first - currElev) <= H)
		{
			bool1 = DFS(N, H, make_pair(row + 1, col), elev);
		}
	}
	//if the left square meter is within map
	if (col-1 >= 0)
	{
		pair<int, bool> leftNode = elev[row ][col-1];
		if (leftNode.second == false && abs(leftNode.first - currElev) <= H)
		{
			bool2 = DFS(N, H, make_pair(row, col - 1), elev);
		}
	}
	//if the right square meter is within map
	if (col+1 < N)
	{
		pair<int, bool> rightNode = elev[row][col+1];
		if (rightNode.second == false && abs(rightNode.first - currElev) <= H)
		{
			bool3 = DFS(N, H, make_pair(row, col + 1), elev);
		}
	}
	
	return (bool1 || bool2 || bool3 || false);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, H;
	cin >> N >> H;

	vector<vector<pair<int, bool>>> elev(N, vector<pair<int, bool>>(N, make_pair(0, false)));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			elev[i][j].first = a;
		}
	}


	if (DFS(N, H, make_pair(0, 0), elev))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}

	




		
}


