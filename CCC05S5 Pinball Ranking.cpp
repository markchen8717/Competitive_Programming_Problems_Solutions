/*
CCC '05 S5 - Pinball Ranking

https://dmoj.ca/problem/ccc05s5

Canadian Computing Competition: 2005 Stage 1, Senior #5

Pinball is an arcade game in which an individual player controls a silver ball by means of flippers, with the objective of accumulating as many points as possible. At the end of each game, the player's score and rank are displayed. The score, an integer between 00 and 10000000001000000000, is that achieved by the player in the game just ended. The rank is displayed as "rr of nn". nn is the total number of games ever played on the machine, and rr is the position of the score for the just-ended game within this set.

More precisely, rr is one greater than the number of games whose score exceeds that of the game just ended.

Input Specification

You are to implement the pinball machine's ranking algorithm. The first line of input contains a positive integer, tt, the total number of games played in the lifetime of the machine. tt lines follow, given the scores of these games, in chronological order.

Output Specification

You are to output the average of the ranks (rounded to two digits after the decimal) that would be displayed on the board. At least one test case will have t≤100t≤100. All test cases will have t≤100000t≤100000.

Sample Input

Copy
5
100
200
150
170
50
Sample Output

Copy
2.20
Explanation

The pinball screen would display (in turn):

Copy
1 of 1
1 of 2
2 of 3
2 of 4
5 of 5
The average rank is (1+1+2+2+5)/5=2.20(1+1+2+2+5)/5=2.20.
*/

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

