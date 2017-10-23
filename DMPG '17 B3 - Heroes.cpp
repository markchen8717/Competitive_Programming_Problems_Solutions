/*
DMPG '17 B3 - Heroes

https://dmoj.ca/problem/dmpg17b3

Roger is addicted to the game Fire Emblem Heroes! His main hero is Hector, who has hHhH health and deals dHdH damage per turn. Hector is up against a foe who deals dFdF damage per turn, and has hFhF health. However, Hector's special, Buckler, activates every 4th turn and negates all damage done against him in that turn, as well as continues to deal the regular amount of damage.

Given NN of these enemies, can you find out who will come out victorious if Hector attacks first, and how many turns it will take?

Note: assume the turn counter, as well as Hector's health, reset with each foe.

Subtasks

Subtask 1 [60%]

1≤N≤10001≤N≤1000

1≤hH,dH,hF,dF≤1001≤hH,dH,hF,dF≤100

Subtask 2 [40%]

1≤N≤1061≤N≤106

1≤hH,dH,hF,dF≤1091≤hH,dH,hF,dF≤109

Input Specification

Line 11: Three space separated integers, NN, hHhH, and dHdH.
Lines 2…N+12…N+1: Two space separated integer, the hFhF and dFdF for each foe.

Output Specification

NN lines, of the format Win x if Hector wins in xx turns, or Lose x, if Hector loses in xx turns.

Sample Input

Copy
4 12 5
4 2
999 999
5 12
20 3

Sample Output

Copy
Win 1
Lose 1
Win 1
Win 4

*/

#include <iostream>
#include <string>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long int N;
	long int hF;
	long  int hD;

	cin >> N >> hF >> hD;
	long   int fF;
	long  int fD;
	long  int temphF;
	

	for (long int i = 0; i < N; i++)
	{
		
		
		temphF = hF;
		cin >> fF >> fD;
		
		long int j = 1;
		while (true)
		{
			
			fF -= hD;
			if (fF <= 0)
				break;
			if (j % 4 != 0)
			{
				temphF -= fD;
				if (temphF <= 0)
					break;
			}

			
			j++;
		}
		
		if (temphF <= 0)
			cout << "Lose " << j << "\n";
		else
			cout << "Win " << j << "\n" ;
	}


    
}
