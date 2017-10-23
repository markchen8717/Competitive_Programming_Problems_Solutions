/*

DMPG '16 B1 - BFS

https://dmoj.ca/problem/dmpg16b1

Bob is your ordinary university student who waits tables at the local restaurant. However, Bob (as with all aspiring adolescents) is burdened with his crushing student debt and due to the stress, he cannot exhibit the maximum potential of his academic performance. To relieve himself of this stress, Bob engages in various recreational activities. One such activity is counting money.

Bob's First Salary is a very important milestone in his life. Luckily, Bob received his tips and wages in Canadian Currency meaning he can run home and count his money over and over again!

Input Specification

Five space-separated integers: NN, DD, QQ, LL, TT indicating the quantity of each currency Bob received from work (0≤N,D,Q,L,T≤10)(0≤N,D,Q,L,T≤10).
These variables represent the collective amount of money Bob received in nickels, dimes, quarters, loonies, and toonies respectively.

Coins	NN	DD	QQ	LL	TT
Value	5¢5¢	10¢10¢	25¢25¢	100¢100¢	200¢200¢
Output Specification

Your program should output the value of Bob's First Salary in cents.

Sample Input

Copy
0 0 0 1 0
Sample Output

Copy
100
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d, q, l, t;
	cin >> n >> d>> q>>l>> t;
	cout << (n*5 + d* 10 + q*25 + l * 100 + t * 200);

	return 0;
}
