/*
TLE '16 Contest 6 (Mock CCC) J1 - Paper Printing

https://dmoj.ca/problem/tle16c6j1

Leon has recently purchased a defective printer that won't stop printing! Once powered on, the printer immediately draws from the initial feed of NN paper and spews it out the front once every second.

He plans to perform AA actions during the printer's operation: for the ithith action, YiYi paper will be either added to or removed from the feed at XiXi seconds since powering on the printer.

Keep in mind that the feed has a maximum capacity MM of paper that it can hold - additional paper forced into the feed would cause a paper jam!

However, if at any given second the printer's feed is empty, it will attempt (but fail) to continuously draw paper. As a result, the printer will rapidly overheat, causing it to quickly melt after a full second (unfortunately short-circuiting, like CCC Junior, doesn't pay).

What will become of Leon's printer?

Input Specification

The first line contains two spaced integers NN and MM (0≤N≤M≤10000≤N≤M≤1000), the initial paper amount and the maximum printer feed capacity, respectively.

The next line contains an integer AA (0≤A≤100≤A≤10), the number of actions to follow.

The next AA lines contain two spaced integers XiXi and YiYi (0≤Xi≤2000,−500≤Yi≤5000≤Xi≤2000,−500≤Yi≤500), describing that YiYi paper was either added to or removed from the feed at XiXi seconds. Actions are listed in chronological order, and only one action can occur in a second. A negative YiYi value means that paper is to be taken away from the feed. You may assume that Leon will never remove more paper from the feed than there currently is.

Output Specification

When and how Leon's printer breaks. Follow the output formats shown below.

Sample Input 1

Copy
4 10
3
2 6
5 -2
8 11
Sample Output 1

Copy
The printer jams at 8 second(s).
Sample Input 2

Copy
4 10
3
2 6
5 -3
8 11
Sample Output 2

Copy
The printer melts at 8 second(s).
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, A;
	cin >> N >> M >> A;
	static int time[2010] = { 0 };
	for (int i = 0; i < A; i++)
	{
		int index, value;
		cin >> index >> value;
		time[index] = value;
	}

	for (int i = 0; i < 900000; i++)
	{
		
		N += time[i];
		if (N > M)
		{
			cout << "The printer jams at " << i << " second(s).";
			break;
		}
		if (N <= 0)
		{
			cout << "The printer melts at " << i+ 1 << " second(s).";
			break;
		}
		
		
		N--;

	}
}
