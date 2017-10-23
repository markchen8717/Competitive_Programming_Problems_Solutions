/*
DMPG '16 B2 - Reward Reminiscence

https://dmoj.ca/problem/dmpg16b2

After counting his money several hundred times, Bob's stress began melting away and his passion to become an expert in gathering intelligence was rekindled. In fact, Bob's inner potential was so great he attracted the attention of the International Organization of Intelligence at the age of 1313!

The IOI hosts an annual competition for post-baccalaureate students, with considerable monetary awards paid out to top-ranking contestants. If NN represents the total number of contestants, and MM represents the number of people possessing a strictly greater score than Bob, then Bob will take home (N−M)−−−−−−−−√×100(N−M)×100 dollars.

Bob was so passionate about the competitions themselves that he forgot to count his winnings. Help Bob determine his winnings for each contest!

Input Specification

The first line of the input contains a single integer TT denoting the number test cases to follow (1≤T≤10)(1≤T≤10).

Every test case consists of exactly 22 lines. The first line of each test case contains two space-separated integers:
NN, the total number of contestants (2≤N≤25)(2≤N≤25), and BB, Bob's score during the competition (1≤B≤104)(1≤B≤104).

The second line of each case contains N−1N−1 space-separated integers SiSi (1≤Si≤104)(1≤Si≤104), representing the score of the i−thi−th contestant in no particular order (excluding Bob, the N−thN−th contestant).

Output Specification

Your program should output TT lines, with each line containing the string Bob wins $D at IOI!, where DD is the amount Bob wins at the competition, rounded to exactly two decimal places.

Sample Input

Copy
1
5 2399
2400 2400 2399 2399
Sample Output

Copy
Bob wins $173.21 at IOI!
Explanation

With his score of 23992399, Bob manages to secure his spot behind only 22 people. As a result, he is awarded (5−2)−−−−−−√×100≈$173.21
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, N, B;
	double output = 0;
	int S [99999] ;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> B;
		for (int k = 0; k < N-1; k++)
		{
			cin >> S[k];
		}
		S[N-1] = B;
		sort(S, S + N);
		int index;
		for (int j = 0; j < N; j++)
		{
			if (S[j] > B)
			{
				index = j;
				break;
			}
		}
		
		output = sqrt(N - (N - index )) * 100;
		cout << "Bob wins $" << setprecision(2) << fixed << output << " at IOI!"<<"\n";
	}

	


}
