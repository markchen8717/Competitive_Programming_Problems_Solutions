// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	bool round = false;
	int i = s.length() - 1;
	do {

		char letter = s[i];

		if (i == 0)
		{

			if (letter >= 110 && letter <= 122)
			{
				s[i] = 'a';
				s = 'a' + s;

			}
			break;
		}
		else {
			if (letter >= 110 && letter <= 122) {
				if (s[i - 1] == 'z')
					round = true;
				else
				{
					s[i - 1] = (int)s[i - 1] + 1;
					round = false;
				}
			}

			s[i] = 'a';

		}
		if (round)
			i--;



	} while (round);
	


	

	cout << s;




	return 0;
}

