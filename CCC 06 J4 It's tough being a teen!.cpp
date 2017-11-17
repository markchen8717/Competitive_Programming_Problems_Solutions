// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> inDeg(8);
	vector<vector<int>> adj(8);
	adj[1].push_back(7);
	inDeg[7]++;
	adj[1].push_back(4);
	inDeg[4]++;
	adj[2].push_back(1);
	inDeg[1]++;
	adj[3].push_back(4);
	inDeg[4]++;
	adj[3].push_back(5);
	inDeg[5]++;

	while (true)
	{
		int a;
		int b;
		cin >> a;
		cin >> b;
		if (a == 0 && b == 0)
			break;
		else
		{
			adj[a].push_back(b);
			inDeg[b]++;
		}

	}

	// Creates a min heap
	priority_queue <int, vector<int>, greater<int> > pq;
	queue<int> output;

	for (int i = 1; i <= 7; i++)
	{
		if (inDeg[i] == 0)
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int key = pq.top();
		output.push(key);
		pq.pop();

		for (int i = 0; i < adj[key].size(); i++)
		{
			int nodeNum = adj[key][i];
			inDeg[nodeNum]--;
			if (inDeg[nodeNum] == 0)
			{
				pq.push(nodeNum);
			}



		}
	}

	if (output.size() == 7 )
	{
		while (!output.empty())
		{
			cout << output.front()<<" ";
			output.pop();
		}
	}	
		
	else {
		cout << "Cannot complete these tasks. Going to bed.";
	}


	

	return 0;
}

