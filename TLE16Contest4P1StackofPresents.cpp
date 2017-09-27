// TLE16Contest4P1StackofPresents.cpp : Defines the entry point for the console application.
//

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
