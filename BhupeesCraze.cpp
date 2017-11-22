/*
Bhupee's Craze 

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/bhupees-craze-7d960eab-24ff51e3/

Craze of programming always have been there in industries, so maximum number of companies are trying to get in touch with good programmers. For this a well established company "SundayCoders" is organizing a party for interested programmers.Bhupee is interested for this function too. But here comes a problem, the party is open for couples only. So he asked his friends to help him out. They suggested him some names,but due to Bhupee's obsession towards factorials, he will select the girl whose name has minimum factorial value of the occurence of unique characters. Can you help him out?(Move to sample i/o for further details):

Input Format:

First line of input will contain an integer T, number of TestCases. First line of each testcase will contain an integer N(number of names). Each of Next N lines will contain a string consisting of lowercase alphabets only.

Output Format:

Print T lines, each line having string (Minimum factorial value of the occurence of unique characters in names). If there is no name the output will be previous string.

Constraints:

1 <= T <= 100 0 <= N <= 25 1 <= length(string) <= 50

Note:- If more than one name have same factorial value, print the last one.

Sample Input:

2
3
sarahah
akanksha
aparana
5
saraswati
shyamapadmavatialkasundarishushmavati
shivgami
devsena
deeksha
Sample Output:

aparana
deeksha
*/


 
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

