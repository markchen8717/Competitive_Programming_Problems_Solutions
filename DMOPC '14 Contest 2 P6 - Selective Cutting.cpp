/*
DMOPC '14 Contest 2 P6 - Selective Cutting 

https://dmoj.ca/problem/dmopc14c2p6

The Logging Company has been hit with a petition from concerned citizens regarding their uncontrolled tree-cutting. For public relations purposes, they have decided that, moving forward, they will only cut down trees with mass above a certain threshold.

The Logging Company has a line of NN (1≤N≤100000)(1≤N≤100000) trees. Each tree ii has a mass mimi (1≤mi≤20000)(1≤mi≤20000). The Company wants to cut some of the trees, so they've hired you to calculate the mass of all the wood they would get from cutting all the trees with mimi greater than or equal to qq (1≤q≤20000)(1≤q≤20000) between positions aa and bb inclusive (0≤a≤b<N)(0≤a≤b<N). In particular, they want you to answer QQ (1≤Q≤100000)(1≤Q≤100000) such queries.

Input Specification

The first line will contain the integer NN. For each tree ii, the ithith (from 0) integer on th second line will contain the integer mass mimi. The third line will contain the number QQ, the number of queries the logging company wants you to answer. The next QQ lines will contain three integers aa and bb and qq.

Output Specification

For each query, print the total mass of the trees at position ii such that a≤i≤ba≤i≤b, and mi≥qmi≥q.

Sample Input

Copy
5
1 3 4 2 5
5
0 4 3
1 3 2
0 4 5
4 4 1
0 4 1
Sample Output

Copy
12
9
5
5
15



*/



 
#include <bits/stdc++.h>
using namespace std;
void update(int x, int v, int N, vector<int> &BIT)
{
	while (x <= N)
	{
		BIT[x] += v;
		x += x&-x;
	}
}
int query(int x, vector<int> &BIT)
{
	int output = 0;
	while (x > 0)
	{
		output += BIT[x];
		x -= x&-x;
	}
	return output;
}

// structure to hold queries
struct Query
{
	int l, r, x, idx, output;
};

// bool function to sort queries according to x
bool cmp1(Query q1, Query q2)
{
	return q1.x > q2.x;
}

// bool function to sort queries according to index
bool cmp2(Query q1, Query q2)
{
	return q1.idx < q2.idx;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N;
	vector<pair<int, int>>mass(N);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		mass[i].first = a;
		mass[i].second = i;
	}
	sort(mass.rbegin(), mass.rend());

	//Queries
	cin >> Q;
	vector<Query> queryArr(Q);
	for (int i = 0; i < Q; i++)
	{
		int l;
		cin >> l;
		int r;
		cin >> r;
		int x;
		cin >> x;
		queryArr[i].idx = i;
		queryArr[i].l = l;
		queryArr[i].r = r;
		queryArr[i].x = x;

	}
	sort(queryArr.begin(), queryArr.end(), cmp1); // sort according to x

	int Z = 0;
	//BIT of mass;
	vector<int>BIT(N + 1, 0);
	for (int i = 0; i < Q; i++)
	{
		int qVal = queryArr[i].x;
		for (; Z < N; Z++)
		{
			if (mass[Z].first >= qVal)
			{
				update(mass[Z].second + 1, mass[Z].first, N, BIT);
			}
			else
				break;
		}
		int sumtwo = query(queryArr[i].r + 1, BIT);
		int sumone = query(queryArr[i].l, BIT);
		queryArr[i].output = sumtwo - sumone;

	}

	sort(queryArr.begin(), queryArr.end(), cmp2);
	for (int i = 0; i < Q; i++)
	{
		cout << queryArr[i].output << "\n";
	}


	return 0;
}

