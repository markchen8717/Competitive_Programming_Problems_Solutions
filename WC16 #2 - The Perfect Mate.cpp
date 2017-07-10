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

