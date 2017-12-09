/*
CCC '10 S4 - Animal Farm
https://dmoj.ca/problem/ccc10s4

Canadian Computing Competition: 2010 Stage 1, Senior #4

You are running a farm which has NN (1≤N≤1001≤N≤100) animals. You went to the store and bought M=NM=N pre-made pens that will house your animals. Pens satisfy the following conditions:

pens have between 33 and 88 edges;
an edge that is specified by two pens connects the two pens;
an edge that is specified only once connects that pen to the outside;
there is exactly one animal in each pen and no animals outside the pens, initially.
The animals, however, have a game they like to play called "Escape from the pen." They assign a cost to each edge of the pen, and they determine the minimum cost for all of the animals to meet in the same area by trampling over the edge of various pens. The animals may meet inside a particular pen or outside of all the pens. Also note that once an edge has been trampled, any animal may pass over it without incurring any cost.

You will be given a description of the pens, along with the placement of animals, and you are to figure out what the smallest cost is to move all the animals into the same area.

Input Specification

The first line of input will be the integer MM, the number of pens. On the next MM lines, there will be a description of each pen, with one description per line. The description is composed of three components, with each component separated by one space, as follows:

the first component is an integer epep (3≤ep≤83≤ep≤8), which describes the number of edges for this particular pen pp;
the second component is a sequence of epep integers describing the corners of each pen, where each integer is less than or equal to 10001000;
the third component is a sequence of epep integers describing the cost of each edge, where each integer is less than or equal to 50005000.
For the corner and edge cost description, the descriptions are given in cyclical order. For example, the following description of a pen

3 1 2 3 7 4 6
3 1 2 3 7 4 6

means that there are three corners, and thus, three edges, where the edge (1,2)(1,2) has cost 77, the edge (2,3)(2,3) has cost 44 and the edge (3,1)(3,1) has cost 66. Note: at least 20% of the marks for this question have N≤10N≤10 and no pen will have more than four edges in these cases.

Output Specification

On one line, output the minimal cost that will allow all the animals to gather in one pen or outside all of the pens.

Sample Input

Copy
4
3 1 2 3 7 4 6
4 1 2 4 5 7 7 2 6
4 4 7 6 5 4 8 9 2
5 3 2 4 7 8 4 7 4 7 7
Output for Sample Input

Copy
10
Explanation of Output for Sample Input

The diagram below explains the input data:


where the circled numbers are the corners, and the numbers in italics are the edge costs. Notice that if the edges (2,3)(2,3), (4,5)(4,5) and (4,7)(4,7) are removed, all the animals can meet in the pen which has five sides.
*/
#include <bits/stdc++.h>

using namespace std;

int n;

pair<int, int> input[1001][1001];

int corners[1001];
int weights[1001];

int adj[101][101];
bool vis[101];
int dis[101];



int prim(int size)
{
	memset(vis, false, sizeof(vis));
	memset(dis, -1, sizeof(dis));
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	int mst = 0;
	int currNode = 0;
	vis[currNode] = true;
	dis[currNode] = 0;

	for (int i = 0; i < size; i++)
	{
		if (adj[currNode][i] != -1)
			pq.push({ adj[currNode][i] ,i });
	}

	while (!pq.empty())
	{
		while (!pq.empty())
		{
			if (vis[pq.top().second])
				pq.pop();
			else
				break;
		}
		if (pq.empty()) break;
		currNode = pq.top().second;
		vis[currNode] = true;
		dis[currNode] = pq.top().first;
		mst += dis[currNode];
		pq.pop();
		for (int i = 0; i < size; i++)
		{
			if (adj[currNode][i] != -1)
				pq.push({ adj[currNode][i] ,i });
		}
	}

	return mst;

}


int main() {




	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			input[i][j] = { -1,0 };

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			adj[i][j] = -1;

	for (int i = 0; i < 101; i++)
		adj[i][i] = 0;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
			cin >> corners[j];
		for (int j = 0; j < k; j++)
			cin >> weights[j];
		for (int j = 0; j < k; j++)
		{
			int z = (j + 1) % k;
			if (input[corners[j]][corners[z]].second > 0)
			{
				if (adj[i][input[corners[j]][corners[z]].first] > weights[j] || adj[i][input[corners[j]][corners[z]].first] == -1)
				{
					adj[i][input[corners[j]][corners[z]].first] = weights[j];
					adj[input[corners[j]][corners[z]].first][i] = weights[j];
					

				}
				input[corners[z]][corners[j]].first = -1;
				input[corners[j]][corners[z]].first = -1;
			}
			else
			{
				input[corners[j]][corners[z]].second = weights[j];
				input[corners[z]][corners[j]].second = weights[j];
				input[corners[j]][corners[z]].first = i;
				input[corners[z]][corners[j]].first = i;

			}
		}


	}
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			if (input[j][i].first >= 0)
			{
				if (adj[input[j][i].first][n] > input[j][i].second || adj[input[j][i].first][n] == -1)
				{
					adj[input[j][i].first][n] = input[j][i].second;
					adj[n][input[j][i].first] = input[j][i].second;


				}
			}
		}
	}

	bool a = false;
	int prim1 = prim(n);
	for (int i = 0; i < n; i++)
	{
		if (vis[i] == false)

		{
			a = true;
			break;
		}
	}


	int prim2 = prim(n + 1);

	if (a)
		cout << prim2;
	else
		cout << min(prim1, prim2);




}
