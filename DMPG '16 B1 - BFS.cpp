

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, N, B;
	double output = 0;
	int S [99999] ;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> B;
		for (int k = 0; k < N-1; k++)
		{
			cin >> S[k];
		}
		S[N-1] = B;
		sort(S, S + N);
		int index;
		for (int j = 0; j < N; j++)
		{
			if (S[j] > B)
			{
				index = j;
				break;
			}
		}
		
		output = sqrt(N - (N - index )) * 100;
		cout << "Bob wins $" << setprecision(2) << fixed << output << " at IOI!"<<"\n";
	}

	


}

