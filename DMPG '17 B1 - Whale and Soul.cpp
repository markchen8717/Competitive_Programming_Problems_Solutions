/*
DMPG '17 B1 - Whale and Soul

https://dmoj.ca/problem/dmpg17b1

In the context of online games, a whale is a player who spends great sums of real money on video games. A certain whale has discovered NN different membership options for a game they play, with the ii-th costing cici dollars and lasting didi days. Keeping in mind that this whale would like to have membership for as long as possible while minimizing how much they swipe their credit card for, can you help them determine the best membership option?

Input Specification

Line 11: a single integer, NN.
Lines 2…N+12…N+1: line ii will contain two space separated integers, cici and didi.

Output Specification

Two space separated integers, the values cici and didi representing the best membership.

Constraints

1≤N≤101≤N≤10
1≤ci,di≤1001≤ci,di≤100

Sample Input

Copy
3
1 4
2 1
1 1
Sample Output

Copy
1 4
Explanation for Sample Output

The first membership lasts for 4 days, which is greater than the duration of the other two memberships (lasting only 11 day).

Since it is the cheapest membership (in this case, the only one) lasting 44 days, the whale should take it.

*/

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
