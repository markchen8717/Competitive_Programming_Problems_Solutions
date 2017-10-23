/*
RGPC '17 P1 - Circle Clicking!

https://dmoj.ca/problem/rgpc17p1

Kashif is a pretty big weeb Japanese animation enthusiast, so it's no surprise that he enjoys playing osu!, an anime-themed rhythm game. In this game, circles appear one-by-one on the screen, and players are required to move their cursor to them and click on them at just the right time to get points.

New circles usually appear close the positions of previous circles, but they may occasionally appear on the other side of the screen as well (called "jumps"). Kashif can play well when the distance between two sequential circles is less than or equal to DD, but if the distance is too great, he misses, and his combo (number of successful hits before the miss) resets to 0.

Given a sequence of coordinates of circles (points) in the form (xi,yi)(xi,yi), Kashif wants to know what his greatest possible combo is, if he always hits the first point. For the purpose of this problem, assume that circles can only be hit at exactly the specified point.

Input Specification

The first line will contain 2 space-separated integers NN (1≤N≤100000)(1≤N≤100000) and DD (1≤D≤1000)(1≤D≤1000), representing the total number of circles in the sequence and Kashif's greatest jump distance respectively.

The next NN lines will each contain 2 space-separated integers xixi and yiyi, (−1000≤xi,yi≤1000)(−1000≤xi,yi≤1000), representing the coordinates of the ithith circle.

Output Specification

Output a single integer representing the longest possible combo Kashif can achieve.

Sample Input

Copy
5 5
0 0
1 1
2 1
2 -6
-1 -4
Sample Output

Copy
3
*/

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
