/*
Code Jam Qualification Round A.Oversized Pancake Flipper
https://code.google.com/codejam/contest/3264486/dashboard

Problem

Last year, the Infinite House of Pancakes introduced a new kind of pancake. It has a happy face made of chocolate chips on one side (the "happy side"), and nothing on the other side (the "blank side").

You are the head cook on duty. The pancakes are cooked in a single row over a hot surface. As part of its infinite efforts to maximize efficiency, the House has recently given you an oversized pancake flipper that flips exactly K consecutive pancakes. That is, in that range of K pancakes, it changes every happy-side pancake to a blank-side pancake, and vice versa; it does not change the left-to-right order of those pancakes.

You cannot flip fewer than K pancakes at a time with the flipper, even at the ends of the row (since there are raised borders on both sides of the cooking surface). For example, you can flip the first K pancakes, but not the first K - 1 pancakes.

Your apprentice cook, who is still learning the job, just used the old-fashioned single-pancake flipper to flip some individual pancakes and then ran to the restroom with it, right before the time when customers come to visit the kitchen. You only have the oversized pancake flipper left, and you need to use it quickly to leave all the cooking pancakes happy side up, so that the customers leave feeling happy with their visit.

Given the current state of the pancakes, calculate the minimum number of uses of the oversized pancake flipper needed to leave all pancakes happy side up, or state that there is no way to do it.

Input

The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with a string S and an integer K. S represents the row of pancakes: each of its characters is either + (which represents a pancake that is initially happy side up) or - (which represents a pancake that is initially blank side up).

Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is either IMPOSSIBLE if there is no way to get all the pancakes happy side up, or an integer representing the the minimum number of times you will need to use the oversized pancake flipper to do it.

Limits

1 ≤ T ≤ 100.
Every character in S is either + or -.
2 ≤ K ≤ length of S.
Small dataset

2 ≤ length of S ≤ 10.
Large dataset

2 ≤ length of S ≤ 1000.
Sample


Input 
 	
Output 
 
3
---+-++- 3
+++++ 4
-+-+- 4

Case #1: 3
Case #2: 0
Case #3: IMPOSSIBLE
In Case #1, you can get all the pancakes happy side up by first flipping the leftmost 3 pancakes, getting to ++++-++-, then the rightmost 3, getting to ++++---+, and finally the 3 pancakes that remain blank side up. There are other ways to do it with 3 flips or more, but none with fewer than 3 flips.

In Case #2, all of the pancakes are already happy side up, so there is no need to flip any of them.

In Case #3, there is no way to make the second and third pancakes from the left have the same side up, because any flip flips them both. Therefore, there is no way to make all of the pancakes happy side up.



*/
#include <iostream>

#include <bits/stdc++.h>
 
using namespace std;



struct Car {


	char dir;
	int inDeg = 0;
	vector<pair<int, int>> adj;
	bool visited = false;

};

void search(map<pair<int, int>, Car> &cars, pair<int, int> x, int N, int M)
{
	if (!cars[x].visited)
	{
		cars[x].visited = true;
		if (cars[x].dir == 'N')
		{
			for (int j = x.first - 1; j >= 0; j--)
			{
				if (!(cars.find(make_pair(j, x.second)) == cars.end())) {
					//  found
					cars[x].inDeg++;
					cars[make_pair(j, x.second)].adj.push_back(x);
					search(cars, make_pair(j, x.second), N, M);
					break;
				}

			}


		}
		else if (cars[x].dir == 'S')
		{
			for (int j = x.first + 1; j < N; j++)
			{
				if (!(cars.find(make_pair(j, x.second)) == cars.end())) {
					//  found
					cars[x].inDeg++;
					cars[make_pair(j, x.second)].adj.push_back(x);
					search(cars, make_pair(j, x.second), N, M);
					break;
				}

			}

		}
		else if (cars[x].dir == 'E')
		{
			for (int j = x.second + 1; j < M; j++)
			{
				if (!(cars.find(make_pair(x.first, j)) == cars.end())) {
					//  found
					cars[x].inDeg++;
					cars[make_pair(x.first, j)].adj.push_back(x);
					search(cars, make_pair(x.first, j), N, M);
					break;
				}

			}
		}
		else if (cars[x].dir == 'W')
		{
			for (int j = x.second - 1; j >= 0; j--)
			{
				if (!(cars.find(make_pair(x.first, j)) == cars.end())) {
					//  found
					cars[x].inDeg++;
					cars[make_pair(x.first, j)].adj.push_back(x);
					search(cars, make_pair(x.first, j), N, M);
					break;
				}

			}
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	

	map<pair<int, int>, Car> cars;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char input;
			cin >> input;
		
			if (input == 'N' || input == 'S' || input == 'E' || input == 'W')
			{
				Car car;
				car.dir = input;
				cars[make_pair(i, j)] = car;
			}
		}
	}

	for (auto & x : cars) 
	{	
		if (!x.second.visited)
		{
			search(cars, x.first,N,M);			
		}
	}

	queue <pair<int, int>> q;

	for (auto & x : cars)
	{
		if (x.second.inDeg == 0)
		{
			q.push(x.first);
		}
	}

	while (!q.empty())
	{
		
		
		cout << '(' << q.front().first << ',' << q.front().second << ')' << "\n";
		cars[q.front()].inDeg--;
		for (auto & x : cars[q.front()].adj)
		{
			
			cars[x].inDeg--;
			
			if (cars[x].inDeg == 0)
			{
				q.push(x);
			}
		}
		q.pop();
	}



}
