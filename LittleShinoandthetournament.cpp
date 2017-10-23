/*
Little Shino and the tournament

https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/little-shino-and-the-tournament/

Little Shino is interested in the fighting tournaments. Once she went to watch one of the tournaments. There were 
N
N fighters and 
i
t
h
ith fighter will be represented by 
i
i. Each fighter has some distinct strength. Rules of the tournament are:

Each fight will have 2 fighters.
In a fight, fighter with more strength will win.
In one round, 1st fighter will fight against 2nd fighter, 3rd fighter will fight against 4th fighter and so on. If there is odd number of fighters, last one will qualify to the next round without fighting.
Input:
First line contains 
2
2 integers, 
N
N and 
Q
Q, number of fighters and number of queries.
Second line contains 
N
N space separated integers. 
k
t
h
kth integer represents the strength of 
k
t
h
kth fighter.
Next 
Q
Q line contain one integer 
i
i each, denoting 
Q
Q queries.

Output:
For each query, print the number of fights 
i
t
h
ith fighter will take part in.

Constraints:
 1
≤
N
≤
10
5
1≤N≤105
 1
≤
Q
≤
10
6
1≤Q≤106
 1
≤
i
≤
N
1≤i≤N
 1
≤
s
t
r
e
n
g
t
h
o
f
f
i
g
h
t
e
r
s
≤
10
9
1≤strengthoffighters≤109
SAMPLE INPUT 
5 5
1 2 3 4 5
1
2
3
4
5
SAMPLE OUTPUT 
1
2
1
3
1
Explanation
The fights in first round will be between (1, 2) and (3, 4).
From fight between (1, 2), 2 will win and from fight between (3, 4), 4 will win.
Second round will have 3 fighters left. {2, 4, 5}.
In second round there will be one fight between (2, 4) and 4 will win the fight.
Third round will have 2 fighters left. {4, 5}
There will one fight in the third round between (4, 5) and 5 will win in the fight.
Number of fight 1 took part in: 1
Number of fight 2 took part in: 2
Number of fight 3 took part in: 1
Number of fight 4 took part in: 3
Number of fight 5 took part in: 1
*/


#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n;
	cin >> q;

	int strengths[100031];
	int life[100031];
	int fights[100031];

	for (int i = 1; i <= n; i++)
	{
		cin >> strengths[i];
		life[i] = 1;
		fights[i] = 0;
	}
	int j = 1;
	int k = 1;
	int fight_num = n;
	while (fight_num)
	{
		j = 1;

		while (j <= n)
		{
			if (life[j] == 1)
			{
				k = j + 1;
				while (k <= n)
				{
					if (life[k] == 1)
					{
						fights[j]++;
						fights[k]++;
						if (strengths[j] > strengths[k])
						{
							life[k] = 0;
						}
						else
						{
							life[j] = 0;
						}
						j = k;
						break;
					}
					k++;
				}
			}
			j++;
		}
		fight_num /= 2;
	}



	while (q--) {
		int a;
		cin >> a;
		cout << fights[a] << "\n";
	}





	return 0;
}

