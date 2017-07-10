// WC15 Finals - The Oxford Comma.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	


	
	int a;
	cin >> a;

	string input;
	string temp;
	
	for (int i = 0; i < a; i++)
	{
		cin >> temp;

		input += temp;
		if (i < (a-1))
		input += " ";


	}
	
	string OR = " or ";
	string AND = " and ";
	int foundOR = input.find(OR);
	int foundAND = input.find(AND);
	while (foundOR != string::npos || foundAND != string::npos)
	{

		bool AND_a = false;
		bool OR_a = false;
		if ((foundOR - 1) >= 0)
			OR_a = isalpha(input[foundOR - 1]);
		

		bool OR_b = false;
		bool AND_b = false;
		
		if (input.length() > (foundAND + 5))
			 AND_b = isalpha(input[foundAND + 5]);
		


		if (input.length() > (foundOR + 5))
			 OR_b = isalpha(input[foundOR + 5]);
		
		if ((foundAND - 1) >= 0 )
			AND_a = isalpha(input[foundAND - 1]);
		
		
		if ((OR_a & OR_b) || (AND_a & AND_b))
		{
			if (foundOR != string::npos)
				input.insert(foundOR, 1, ',');
			if (foundAND != string::npos)
				input.insert(foundAND, 1, ',');
			
		}

		 foundOR = input.find(OR,foundOR+1);
		 foundAND = input.find(AND,foundAND+1);

	}
	
	cout << input;

	return 0;
}

