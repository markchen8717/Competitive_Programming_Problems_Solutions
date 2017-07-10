#include <string>
#include <iostream>	
#include <stdio.h>
#include <ctype.h>
using namespace std;


int main()
{
	string input;
	getline(cin, input);
	string str1;
	string str2;
	string output;
	int comma = input.find(',');
	if (input.length() - 1 - comma > 1)
	{
		
		str1 = input.substr(comma+2, input.length() - 3 - comma);

		if (isalpha(str1[0]))
		{ 
			str1[0] = toupper(str1[0]);
		}
		
		
		str2 = input.substr(0, comma);

		if (isalpha(str2[0]))
		{
			str2[0] = tolower(str2[0]);
		}

		output = str1; 
		if (input.length() - comma < input.length())
		{
			

			output += + " " +str2;
		}
		
		output += input.substr(input.length() - 1);

	}
	else
	{
		output = input.substr(0, input.length() - 2) +
			input.substr(input.length() - 1);
	}

	cout << output;


}
