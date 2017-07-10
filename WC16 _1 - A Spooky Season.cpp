// WC16 _1 - A Spooky Season.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "sp";
	int s;
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		input += "o";

	}
	input += "ky";
	cout << input;

	return 0;
}

