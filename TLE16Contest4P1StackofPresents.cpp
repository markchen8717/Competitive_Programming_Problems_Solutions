/*
TLE '16 Contest 4 P1 - Stack of Presents

https://dmoj.ca/problem/tle16c4p1

The CS Nerd is dreaming about giving Christmas presents to the girl. Unfortunately, he does not have enough courage to do this in real life.

In the dream, there are NN presents that he could possibly give to the girl. The ithith present has a weight of wiwi. The CS Nerd wants to impress the girl by building a large stack of presents – that is, presents stacked one on top of each other – and giving it to her.

However, the CS Nerd needs to ensure that the sum of the weights of the presents above any present does not exceed that present's weight. What is the maximum number of presents that can be in the stack?

Input Specification

The first line of input will contain a single integer NN (1≤N≤100000)(1≤N≤100000).

NN lines of input follow. The ithith line will consist of a single integer, wiwi (1≤wi≤109)(1≤wi≤109).

For 20% of the points, N≤10N≤10.

For an additional 30% of the points, N≤1000N≤1000.

Output Specification

Output a single integer, the maximum possible number of presents that can be in the stack.

Sample Input

Copy
5
7
8
2
5
10
Sample Output

Copy
3
Explanation for Sample Output

The CS Nerd can stack presents in the order 22, 44, and 33 from the bottom. The weights of these presents are 88, 55, and 22, respectively. Note that this is not the only possible solution.
*/

#include <iostream>
#include <algorithm>

using namespace std;


int input, sum, cnt;
int weights[100000];

int main()
{

	cin >> input;

	for (int i = 0; i < input; i++)
	{
		cin >> weights[i];
	}

	sort(weights, weights + input);


	for (int i = 0; i < input; i++)
	{
		if (weights[i] >= sum) {
			sum += weights[i];
			cnt++;
		}
	}

	cout << cnt;

}
