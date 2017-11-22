#include "stdafx.h"
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