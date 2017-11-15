// Crossing F.cpp : Defines the entry point for the console application.
//

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


