// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;
void update(int x, int v, int N, vector<int> &BIT)
{
	while (x <= N)
	{
		BIT[x] += v;
		x += x &-x;
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vector <pair<int, int>> score(t+1);
	vector<int> BIT(t + 1, 0);
	for (int i = 1; i <= t; i++)
	{
		int x;
		cin >> x;
		score[i] = make_pair(x, i);
	}
	sort(score.begin(), score.end());
	double rank = 0;
	for (int i = 1; i <= t; i++)
	{
		update(score[i].second, 1, t, BIT);
		rank += score[i].second - query(score[i].second-1, BIT);
	}
	rank /= t;
	printf("%.2f", rank);

	return 0;
}

