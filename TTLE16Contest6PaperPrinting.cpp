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