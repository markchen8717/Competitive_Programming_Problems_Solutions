// DMPG '17 B2 - Yoda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>	
using namespace std;


int main()
{
	string input;
	getline(cin, input);
	
	int comma = input.find(',');
	string str1;
	string str2;
	if (!isalpha(input[comma + 2]))
	{
		cout << input.substr(0, input.length() - 1) + input.substr(input.length() - 1);
	}
	str1 = input.substr(comma+2,input.size()-3-comma);
	str2 = input.substr(0, comma);

	

	string output;
	
	
	str1[0] = str1[0] - 32;
	str2[0] = str2[0] + 32;

	output = str1 + " " + str2 + input.substr(input.size() - 1);


	cout << output;
	



}

