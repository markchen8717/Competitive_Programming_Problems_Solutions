/*
CCC '17 S1 - Sum Game

https://dmoj.ca/problem/ccc17s1

Annie has two favourite baseball teams: the Swifts and the Semaphores. She has followed them throughout the season, which is now over. The season lasted for NN days. Both teams played exactly one game on each day.

For each day, Annie recorded the number of runs scored by the Swifts on that day. She also recorded this information for the Semaphores.

She would like you to determine the largest integer KK such that K≤NK≤N and the Swifts and the Semaphores had scored the same total number of runs KK days after the start of the season. The total number of runs scored by a team after KK days is the sum of the number of runs scored by the team in all games before or on the KK-th day.

For example, if the Swifts and the Semaphores have the same total number of runs at the end of the season, then you should output NN. If the Swifts and the Semaphores never had the same number of runs after KK games, for any value of K≤NK≤N, then output 0.

Input Specification

The first line of input will contain an integer N (1≤N≤100000)N (1≤N≤100000). The second line will contain NN space-separated non-negative integers representing the number of runs scored by the Swifts on each day, in order. The third line will contain NN space-separated non-negative integers representing the number of runs scored by the Semaphores on each day, in order. You may assume that each team scored at most 2020 runs in any single game.

For 7 of the 15 points available, N≤1000N≤1000.

Output Specification

Output the largest integer KK such that K≤NK≤N and the Swifts and the Semaphores have the same total number of runs after KK days.

Sample Input 1

Copy
3
1 3 3
2 2 6
Sample Output 1

Copy
2
Explanation for Sample Output 1

After 2 days, each team had scored a total of 4 runs.

Sample Input 2

Copy
3
1 2 3
4 5 6
Sample Output 2

Copy
0
Explanation for Sample Output 2

The only time when the Swifts and the Semaphores had scored the same number of runs was the beginning of the season.

Sample Input 3

Copy
4
1 2 3 4
1 3 2 4
Sample Output 3

Copy
4
Explanation for Sample Output 3

The Swifts and Semaphores have the same number of total runs after the first game, and after the third game, and after the fourth game. We take the largest of these values (1, 3 and 4) and output 4.
*/

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector <int> swifts(N + 1, 0);
	vector <int> semp(N + 1, 0);
	
		int a;
		cin >> a;
		swifts[1] = a;
		for (int j = 2; j <= N; j++)
		{
			
			cin >> a;
			swifts[j] = swifts[j - 1] + a;
		}

	
		cin >> a;
		semp[1] = a;
		for (int j = 2; j <= N; j++)
		{

			cin >> a;
			semp[j] = semp[j - 1] + a;
		}
		int output = 0;
		for (int i = 1; i <= N; i++)
		{
			if (semp[i] == swifts[i])
			{
				output = i;
				
			}

		}
		cout << output;

	
}

