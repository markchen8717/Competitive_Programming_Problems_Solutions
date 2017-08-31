//  Bhupee's Craze 
//Basic Implementation

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string prev_ans;
	int tc;
	cin >> tc;

	string name;
	int n;
	while (tc--)
	{

		cin >> n;

		int tmp = 26;

		string ans;

		while (n--)
		{
			cin >> name;

			int alpha[26] = { 0 };
			int count = 0;


			for (int i = 0; i < name.size(); i++)
			{
				alpha[name[i] - 'a']++;
			}





			for (int i = 0; i < 26; i++)
			{
				if (alpha[i] != 0)
					count++;
			}


			if (count <= tmp && count != 0)
			{

				tmp = count;
				ans = name;
				prev_ans = ans;


			}


		}
		if (ans == "")
		{

			cout << prev_ans << endl;
		}
		else {
			cout << ans << endl;
		}
	}

	return 0;
}

