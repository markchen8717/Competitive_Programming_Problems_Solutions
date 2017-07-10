// DMPG'16 B3 - CCO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	string symbol [3][1];
	for (int i = 0; i < 3; i++)
	{
		getline (cin,symbol[i][0]);
	}





	int V, H, W;
	cin >> V >> H >> W;
	
	
	
	

	int digit_num = 0;
	if (V <= 999)
	{
		digit_num = 3;
	}
	else
	{
		digit_num = 4;
	}





	//1STLINE
	for (int i = 0; (i < 2 * W + 5); i++)
	{
		cout << '=';
	}



	cout << "\n";



	//body
	for (int i = 0; (i < 2 * H + 3); i++)
	{
		//1st body
		if (i == 0)
		{
			cout << '|' << V;
			for (int i = 0; (i < 2 * W + 5 - digit_num - 2); i++)
			{
				cout << ' ';
			}
			cout << '|' << "\n";
		
		}
	
		else if (i == 0 + H)
		{
			cout << '|';
			for (int i = 0; i < W; i++)
			{
				cout << ' ';
			}
			cout << symbol[0][0];
			for (int i = 0; i < W; i++)
			{
				cout << ' ';
			}
			cout << '|' << "\n";
			
		}

		else if (i == 0 + H + 1)
		{
			cout << '|';
			for (int i = 0; i < W; i++)
			{
				cout << ' ';
			}
			cout << symbol[1][0];
			for (int i = 0; i < W; i++)
			{
				cout << ' ';
			}
			cout << '|' << "\n";
		}
		else if (i == 0 + H + 2)
		{
			cout << '|';
			for (int i = 0; i < W; i++)
			{
				cout << ' ';
			}
			cout << symbol[2][0];
			for (int i = 0; i < W; i++)
			{
				cout << ' ';
			}
			cout << '|' << "\n";
		}





		//mid-body
		else if ((i > 0) && (i != (2 * H + 3) - 1) )
		{
			cout << '|';
			for (int i = 0; (i < 2 * W + 5 - 2); i++)
			{
				cout << ' ';
			}
			cout << '|' << "\n";
			
		}
		
		else if (i == (2 * H + 3) - 1)
		{
			cout << '|';
			for (int i = 0; (i < 2 * W + 5 - digit_num - 2); i++)
			{
				cout << ' ';
			}
			cout << V << '|' << "\n";
		}


	}






	for (int i = 0; (i < 2 * W + 5); i++)
	{
		cout << '=';
	}



}

