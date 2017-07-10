// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include <bits/stdc++.h>
using namespace std;

int getShift(char W, char D)
{
	
	return W - D;
}

int shifter(char D, int shift)
{
	if (D + shift < 97)
	{
		return 122 - (97 - (D + shift)) + 1;
	}
	else if (D + shift > 122)
	{
		return 97 + (97 + (D + shift)) - 1;
	}
	return D + shift;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	string W;
	string D;
	int shift;
	int ans = 0;
	cin >> N >> M;
	cin >> W;
	bool question = true;
	bool word = false;
	for (int i = 0; i < M; i++)// all words
	{
		cin >> D; // take word
		question = true;
		for (int i = 0; i < N; i++)// get every shift from D to W
		{
			if (W[i] == D[i]) 
			{
				break; // stop checking D if Di is equal to Wi
			}
			else if (W[i] != '?')//FOR EVERY W CHAR NOT  '?'
			{
				question = false;
				//cout << "found !? at f:" << i << "\n";
				shift = getShift(W[i], D[i]); // get shift from Di to Wi
				word = false;
			//	cout << "shift:" << shift << "\n";
				for (int i = 0; i < N; i++)// check the shift with all chars
				{
					if (W[i] != '?')
					{
						char test = (char)shifter(D[i], shift);
					//	cout << "test:" << test << "W[i]: " << W[i] << "\n";
						if (test != W[i]) // STOP CHECKING IF ONE CHAR IS INVALID
						{
							//cout << "break" << "\n";
							break;
						}						
					}
					if (i == N - 1) // if check runs to the end 
					{
						word = true;
					}
				}
				if (word)
				{
					ans++;
					break; // next word
				}
			}
			else if (i == N - 1 && question)
			{
				cout << M; // if all of W is '?'
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}
