/*
TLE '17 Contest 1 P1 - String Rounding

https://dmoj.ca/problem/tle17c1p1

Fax McClad, Croneria's most adventurous bounty hunter, has been tasked to explore the unknown planet TR-387. Upon arrival to this planet, he finds a primitive civilization of alien beings. He is surprised to learn that they only use lowercase English letters to represent digits in their number system!

The beings of this planet are particularly fond with a technique called rounding. Here are the rules on how to round a number:

Start with the last (rightmost) digit of the number
If the digit is in between a and m, set the digit to a.
If the digit is in between n and z, set the digit to a and increase the next (left) digit by one character. If the next digit happens to be z, round that character instead of increasing it. If there is no next digit, add a to the left of the number.
Fax wishes to be acquainted with this alien species by showing them that he knows their rounding technique, but he is having difficulty doing so. Given a number SS, can you round it for him?

Input Specification

The first and only line of input will contain SS, a string consisting only of lowercase English letters. SS will contain at least 11 character and at most 100100 characters.

Output Specification

Output one line, the rounded value of SS.

Sample Input 1

Copy
abcdefghijklmnopqrstuvwxyz
Sample Output 1

Copy
abcdefghijklmnopqrstuvwxza
Sample Input 2

Copy
y
Sample Output 2

Copy
aa
Sample Input 3

Copy
faxmcladisthegreatestbountyhunterincroneria
Sample Output 3

Copy
faxmcladisthegreatestbountyhunterincroneria
*/

 
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

