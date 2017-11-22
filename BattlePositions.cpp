/*
Battle Positions 
https://dmoj.ca/problem/seed3
The ZAFT are attacking the Orb Union! There are II stations, numbered from (1,2,…,I−1,I1,2,…,I−1,I), that need to be defended. For it to be secure, the Orb Union needs to have at least NN troops at each station. Unfortunately, due to the radar-jamming effects of the Neutron Jammer, the Orb Union cannot order their troops to move between stations. The Orb Union will send JJ waves of troops, each of which sends KK troops to each of the stations (Xi,Xi+1,…,Xf−1,XfXi,Xi+1,…,Xf−1,Xf). All stations start with 00 troops.

The Orb Union wants you to help them find the number of stations that are not secure.

Input Specification

The first line will contain the integer II (1≤I≤1051≤I≤105), the number of stations.

The second line will contain the integer NN (1≤N≤1091≤N≤109), the minimum number of troops required to defend a station.

The third line will contain the integer JJ (1≤J≤1051≤J≤105), the number of waves of troops.

The next JJ lines will contain 3 space-separated integers. These integers will be in the order XiXi, XfXf, KK (1≤Xi≤Xf≤I)(1≤Xi≤Xf≤I) (1≤K≤104)(1≤K≤104).

Output Specification

Output the total number of stations that have less than NN troops.

Sample Input

Copy
4
1
3
1 3 1
2 3 2
3 3 2
Output for Sample Input

Copy
1

*/

 
#include <bits/stdc++.h>
using namespace std;
int guards[100000];
	int station[100000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int I, N, J;
	cin >> I>>N>>J;
	
	while (J--) {
		int a, b,k;
		cin >> a >> b >> k;
		station[a] += k;
		if(b != 100000)
			station[b + 1] -= k;
	}
	guards[1] = station[1];
	for (int i = 2; i <= I; i++)
	{
		guards[i] = guards[i - 1] + station[i];
	}
	int counter = 0;
	for (int i = 1; i <= I; i++) {
		if (guards[i] < N)
			counter++;
	}
	
	cout << counter;

	return 0;
}

