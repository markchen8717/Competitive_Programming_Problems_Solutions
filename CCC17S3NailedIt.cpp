/*
CCC '17 S3 - Nailed It!

https://dmoj.ca/problem/ccc17s3

Canadian Computing Competition: 2017 Stage 1, Junior #5, Senior #3

Tudor is a contestant in the Canadian Carpentry Challenge (CCC). To win the CCC, Tudor must demonstrate his skill at nailing wood together to make the longest fence possible using boards. To accomplish this goal, he has NN pieces of wood. The ithith piece of wood has integer length LiLi.

A board is made up of exactly two pieces of wood. The length of a board made of wood with lengths LiLi and LjLj is Li+LjLi+Lj. A fence consists of boards that are the same length. The length of the fence is the number of boards used to make it, and the height of the fence is the length of each board in the fence. In the example fence below, the length of the fence is 4; the height of the fence is 50; and, the length of each piece of wood is shown:


Tudor would like to make the longest fence possible. Please help him determine the maximum length of any fence he could make, and the number of different heights a fence of that maximum length could have.

Input Specification

The first line will contain the integer NN (2≤N≤1000000)(2≤N≤1000000).
The second line will contain NN space-separated integers L1,L2,…,LNL1,L2,…,LN (1≤Li≤2000)(1≤Li≤2000).

For 5 of the 15 available marks, N≤100N≤100.
For an additional 4 of the 15 available marks, N≤1000N≤1000.
For an additional 3 of the 15 available marks, N≤100000N≤100000.

Output Specification

Output two integers on a single line separated by a single space: the length of the longest fence and the number of different heights a longest fence could have.

Sample Input 1

Copy
4
1 2 3 4
Sample Output 1

Copy
2 1
Explanation for Sample Output 1

Tudor first combines the pieces of wood with lengths 11 and 44 to form a board of length 55.
Then he combines the pieces of wood with lengths 22 and 33 to form another board of length 55.
Finally, he combines the boards to make a fence with length 22 and height 55.

Sample Input 2

Copy
5
1 10 100 1000 2000
Sample Output 2

Copy
1 10
Explanation for Sample Output 2

Tudor can't make a fence longer than length 11, and there are 1010 ways to make a fence with length 11 by choosing any two pieces of wood to nail together.
Specifically, he may have a fence of height 1111, 101101, 10011001, 20012001, 110110, 10101010, 20102010, 11001100, 21002100 and 30003000.


*/

 
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int length[2004] = { 0 };
	int sums[4004] = { 0 };

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		length[a]++;
	}
	for (int i = 1; i <= 2000; i++)
	{
		if (length[i])
		{
			for (int j = i; j <= 2000; j++)
			{
				if (j == i)
					sums[i + j] += length[i] / 2;
				else if (length[j])
					sums[i + j] += min(length[i], length[j]);
			}
		}
	}
	int ans1 = 0;
	int ans2 = 1;
	for (int i = 1; i <= 4000; i++)
	{
		if (sums[i] > ans1)
		{
			ans1 = sums[i];
			ans2 = 1;
		}
		else if (sums[i] == ans1)
		{
			ans2++;
		}
	}
	cout << ans1 << " " << ans2;

	return 0;
}

