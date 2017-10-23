/*
The Perfect Mate

http://wcipeg.com/problem/wc162j1

Lieutenant B'Elenne Terres is one unsatisfied Klingon. Her engineering working aboard the Starship Enterprise is all well and good, but what she really needs is a mate!

Fortunately for her, the Enterprise has happened across a Klingon colony, which has N (1 ≤ N ≤ 100) warriors living there. The i-th warrior's name is Si (a unique string consisting of at most 20 letters), and according to a survey which Terres has conducted, they've won Wi (0 ≤ Wi ≤ 100) battles and lost Li (0 ≤ Li ≤ 100) battles in their lifetime. She's not too concerned about which of the warriors actually happen to be single at the time.

Any warrior who has lost at least one battle would clearly not make a suitable mate – weakness is unacceptable. Of the warriors who have never lost any battles, the perfect mate is the one who has won the greatest number of battles. If multiple suitable warriors have won the same number of battles, then the one earliest in the list of N warriors is preferable.

Please help Terres determine the name of this perfect mate! Of course, it's also possible that there's no such mate, if none of the N warriors are suitable.

Input Format

The first line of input consists of a single integer N.
N lines follow, with the i-th of these lines consisting of a single string Si, followed by a space, followed by two space-separated integers Wi and Li (for i = 1..N).

Output Format

Output a single line consisting of a single string – either the name of the perfect mate, or "None" if there are no suitable mates.

Sample Input 1

5
Mereg 7 0
Werf 15 10
Kehless 14 0
Kerek 14 0
Stex 2 3
Sample Output 1

Kehless
Sample Input 2

1
Jacob 100 1
Sample Output 2

None
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int num_m8;
	string name;
	int win;
	int loss;
	vector < string > names;
	vector <int> wins;
	cin >> num_m8;

	for (int i = 0; i < num_m8; i++)
	{
		cin >> name;
		cin >> win;
		cin >> loss;
		if (loss == 0)
		{
			names.push_back(name);
			wins.push_back(win);
		}
	}
	if (wins.size() == 0)
	{
		cout << "None";
		return 0;
	}



	int index = 0;
	int tmp = wins[0];
	for (int i = 1; i < wins.size() ; i++)
	{
		if (wins[i] > tmp)
		{
			tmp = wins[i];
			index = i;
		}
	}
	cout << names[index];
	


	return 0;
}

