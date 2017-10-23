/*
Enigmoo

http://wcipeg.com/problem/wc16fj2

Well, this is suspicious… after a year of living in begrudging peace after having been evicted from their homeland of Scarberia, the monkeys have just intercepted a secret message from the cows. The Head Monkey is no fool – this can only mean that her long-time nemesis, Bo Vine, is looking for trouble once again!

The message is a single word, a string W consisting of N (1 ≤ N ≤ 100) lowercase letters. Knowledge of this word may give the monkeys valuable insight into the cows' military plans, but there are two problems.

The first problem is that the string has been encrypted! Fortunately, the Head Monkey is well aware of the naive Enigmoo encryption algorithm which Bo Vine likes to use when transmitting information. Bo Vine has surely chosen some integral shift value S (1 ≤ S ≤ 25), and then cyclically shifted each letter in the string forward in the alphabet by S spots. For example, if S = 2, then the original message "hey" would get encrypted into the string "jga". Note that even Bo Vine wouldn't have been stupid enough to choose S = 0, as that would have resulted in the encrypted string being equal to the original one.

The second problem is that the message may have been damaged, rendering some of its letters unreadable. If the monkeys can't identify the i-th letter in the encrypted string, then Wi = "?". It's possible that all of the letters are still readable, or none of them, or anything in between.

The Head Monkey has dug out her comprehensive dictionary of cow words, which contains M (1 ≤ M ≤ 100) distinct words of length N. The i-th of these words is Di, and consists of N lowercase letters. Given that the cows may have chosen any possible shift value, and that each unreadable letter in W might actually be equal to any lowercase letter, can you help the monkeys narrow their search by counting the number of different words in the dictionary which, when encrypted, might correspond to W? It's possible that the original message is actually some gibberish which doesn't match anything in the dictionary.

In test cases worth 4/13 of the points, none of the characters in W are equal to "?".
In test cases worth another 4/13 of the points, exactly one of the characters in W is equal to "?".

Input Format

The first line of input consists of two space-separated integers N and M.
The second line of input consists of the string W.
M lines follow, the i-th of which consists of the string Di (for i = 1..M).

Output Format

Output one line consisting of a single integer – the number of different words in the dictionary which the encrypted string might match.

Sample Input

6 7
??zz?k
attack
cattle
treats
farmer
missed
battle
sleepy
Sample Output

3
Sample Explanation

The original message might have been "cattle" – if the cows had chosen S = 6, then the encrypted string would've become "igzzrk", which is consistent with the message found by the monkeys.
However, the original message might've also been "battle" (also with S = 6) or "missed" (with S = 7).

*/


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
