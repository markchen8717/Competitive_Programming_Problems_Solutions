// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stack>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N>>M;
	vector<vector<int>> adj(N+1);
	vector<int> inDeg(N+1, 0);
	while (M--)
	{
		int a;
		int b;
		cin >> a;
		cin >> b;
		inDeg[b]++;
		adj[a].push_back(b);
	}
	int count = 0;
	queue<int> nodes;
	for (int i = 1; i <= N; i++)
	{
		if (inDeg[i] == 0)
		{
			nodes.push(i);
		}
	}
	while (!nodes.empty())
	{
		count++;
		int key = nodes.front();
		nodes.pop();

		inDeg[key]--;
		for (int i = 0; i < adj[key].size(); i++)
		{
			int nodeNum = adj[key][i];
			inDeg[nodeNum]--;
			if (inDeg[nodeNum] == 0)
				nodes.push(nodeNum);
		}
	}
	if (count != N)
		cout << "N";
	else
		cout << "Y";

	return 0;
}

