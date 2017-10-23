/*
DMPG '17 B2 - Yoda

https://dmoj.ca/problem/dmpg17b2

Talk like this, Yoda does. Hard to understand, this may be. If given a sentence you are, convert it into English can you? Since difficult this may be, bend the rules of English grammar you may.

Yoda-Speak	English
Talk like this, Yoda does.	Yoda does talk like this.
Hard to understand, this may be.	This may be hard to understand.
If given a sentence you are, convert it into English can you?	Convert it into English can you if given a sentence you are?
Since difficult this may be, bend the rules of English grammar you may.	Bend the rules of English grammar you may since difficult this may be.
Input Specification

The input will be a single string SS, with length no longer than 10001000. It will not start with a lowercase letter, and finish with either a period (.), question mark (?), or exclamation mark (!). Additionally, there will only be a single comma within the string.

Output Specification

The converted string.

Sample Input 1

Copy
Speak like this, Yoda does.
Sample Output 1

Copy
Yoda does speak like this.
Sample Input 2

Copy
English, a language it is.
Sample Output 2

Copy
A language it is english.
Sample Input 3

Copy
Comma at the end,!
Sample Output 3

Copy
Comma at the end!

*/

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
