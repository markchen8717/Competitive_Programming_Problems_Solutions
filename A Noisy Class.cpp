/*
https://dmoj.ca/problem/anoisyclass
One day Mr. Sidhu's class is excessively loud. Unfortunately, giving them an activity about tiles didn't really work.

He notices that when he tells a certain student to stop talking, they will immediately resume since another noisy student will distract them, but if he tells the noisy student to stop talking, there will be silence at last.

After many hours of careful observations, Mr. Sidhu has given you a list containing the connections between students and asks you if it is even possible for the class to be completely silent.

Given the size of his class (as seen in New Students), he can only tell students to stop talking individually. Note that connections are in one direction - the noisy students talk to the distracted students, but not the other way around.

Input Specification:

The first line consists of NN (1≤N≤10000)(1≤N≤10000), the number of students; each student is assigned a number from 11 to NN.
The next line contains MM (1≤M≤10000)(1≤M≤10000), the number of connections.
The next MM lines contain two space-separated integers, representing the noisy student and the distracted student respectively. Given the sheer size, it is not guaranteed that the connections are distinct.

Output Specification

You are to output Y if it is possible and N if it is not.

Sample Input 1:

Copy
4
4
1 2
2 3
2 4
4 3
Sample Output 1:

Copy
Y
Explanation for Sample Input 1:

Mr. Sidhu can tell the students to stop talking in the following order: 1,2,4,31,2,4,3

Sample Input 2:

Copy
2
2
1 2
2 1
Sample Output 2:

Copy
N
Explanation for Sample Input 2:

After telling student 11 to quiet down student 22 will immediately distract him, and vice-versa. Since there is a cycle the class will never be quiet!



*/

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

