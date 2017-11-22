/*
CCC '17 S2 - High Tide, Low Tide

https://dmoj.ca/problem/ccc17s2

Joe Coder is camping near the Bay of Fundy between Nova Scotia and New Brunswick. When he arrived at the bay, he was told that the difference in height between high tide and low tide at the Bay of Fundy was the largest tidal difference in the world. Ever the skeptic, Joe decided to verify this. He chose a reference point and, after learning from the radio when the tides were highest and lowest, he went with a boat to his reference point and measured the depth of the water. Unfortunately, on the last day of his trip, a strong wind scattered his measurements.

Joe has recovered all of his measurements, but they may not be in their original order. Luckily, he remembers some things about his measurements:

He started measuring water levels at a low tide, his second measurement was of the water level at high tide, and after that the measurements continued to alternate between low and high tides.
All high tide measurements were higher than all low tide measurements.
Joe noticed that as time passed, the high tides only became higher and the low tides only became lower.
Given Joe's measurements in no particular order, you must reconstruct the correct order in which the measurements were taken.

Input Specification

The first line contains the integer N (1≤N≤100)N (1≤N≤100). The next line contains NN distinct space-separated positive integers, where each integer is at most 10000001000000.

Output Specification

Output the NN integers in the unique order that Joe originally took the measurements.

Sample Input

Copy
8
10 50 40 7 3 110 90 2
Sample Output

Copy
10 40 7 50 3 90 2 110
Explanation for Sample Output

The low tide measurements (in order) were 1010, 77, 33, and 22.
The high tide measurements (in order) were 4040, 5050, 9090, and 110110.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector <int> tides(N, 0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		tides[i] = a;
	}

	sort(tides.begin(), tides.end());
	int j = ceil(N / 2.0);
	for (int i = j - 1; i >= 0; i--)
	{
		cout << tides[i] << " ";
		if (j < N)
		{
			cout << tides[j] << " ";
			j++;
		}
	}
	return 0;
}
