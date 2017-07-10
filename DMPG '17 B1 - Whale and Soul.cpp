// DMPG '17 B1 - Whale and Soul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int num, c, d;
	int out_c, out_d;
	cin >> num;
	cin >> out_c;
	cin >> out_d;
	for (int i = 1; i < num; i++)
	{
		cin >> c;
		cin >> d;
		if  (d > out_d)
		{
			
			out_d = d;

			
				out_c = c;
		}
		else if (d == out_d)
		{
			if (c < out_c)
				out_c = c;	
		}
	}
	cout << out_c << " " << out_d;

}

