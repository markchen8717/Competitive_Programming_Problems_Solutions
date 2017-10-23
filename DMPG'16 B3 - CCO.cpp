/*

DMPG '16 B3 - CCO

https://dmoj.ca/problem/dmpg16b3

Bob is now so rich that his ambitions for his purchases have begun to spiral out of control. Everything that he once thought would be able to satisfy his needs no longer comes close. The only way to quench such lofty desires is by making money!

Bob is an expert in information security and is able to effectively cover the tracks of his underground affairs. In order to sustain such a herculean operation, he has hired you to help! Help Bob by printing out the design of the Canadian Counterfeiting Operation illegal tender.

Input Specification

Each test case will consist of 33 lines each containing 33 characters, representing the 33 by 33 design to be printed on the bill.

The line afterwards consists of 33 space separated integers VV, HH and WW, representing the value of the bank note (100≤V≤1000)(100≤V≤1000) and the number of line breaks above and below the central design, and the number of spaces to the left and right of the central design (1≤H,W≤50)(1≤H,W≤50) respectively.

Output Specification

Your program should output a rectangular array of characters consisting of = characters (ASCII 6161) along the top and | characters (ASCII 124124) down the sides.

The value of the counterfeit bill should appear justified in the top-left and bottom-right corners of the tender.

The 33 by 33 design given in the input should be centered in the bill, with HH lines of space characters (ASCII 3232) above and below it, and VV space characters bordering it.

Sample Input

Copy
[|]
/ \
\_/
100 1 13
Sample Output

Copy
===============================
|100                          |
|             [|]             |
|             / \             |
|             \_/             |
|                          100|
===============================
*/


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

