#include <bits/stdc++.h>

using namespace std;








int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int circleNum; //num of circles
	double distance; // greatest distance
	int x1; // x1 coordinate
	int y1; // y2 coordinate

	int x2; // x2 coordinate

	int y2; // y2 coordinate
	int combo = 1; // num of combos
	int output = 1;

	cin >> circleNum; //get num of sequences
	cin >> distance; // get max range

	cin >> x1; //get  first coordinates 
	cin >> y1;
	for (int i = 0; i < (circleNum - 1); i++)
	{
		cin >> x2;     //get second coordinates
		cin >> y2;
	
		
		if (sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2)) <= distance)
		// if the absolute vaule of change in x and y is <= distance
		{
			combo++; // add 1 to combo
			
			if (combo > output) // if combo is > output
			{
				output = combo; // make output equal to combo

			}
		}
		else 
		{
			
			combo = 0; // combo reset

		}
		x1 = x2; 
		y1 = y2; 
	}
	cout << output;
}