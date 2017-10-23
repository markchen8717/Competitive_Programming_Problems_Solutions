/*
Rational Recipes

http://wcipeg.com/problem/wc16fs2

The worst has come to pass, with the war between the monkeys and cows now officially in full swing. In fact, the first major battle has been scheduled for next week! As an experienced military leader, the Head Monkey is well aware of the importance of an often under-appreciated aspect of war – the nutritional well-being of the soldiers. She's taken it upon herself to personally prepare the upcoming battle's rations.

The Head Monkey has N (1 ≤ N ≤ 100) different types of fruit ingredients to work with, numbered from 1 to N. Fruit type 1 corresponds to the monkeys' beloved bananas, of course, while the other fruit types are less tasty but have their own nutritional benefits. There are Fi (1 ≤ Fi ≤ 1,000,000,000) fruits of the i-th type available.

The Head Monkey intends to come up with a smoothie recipe, which will call for combining a certain set of fruits together to create a single smoothie. The recipe R will dictate that exactly Ri fruits of type i must go into the smoothie, where Ri is a strictly positive integer for each i between 1 and N. It's unclear exactly what recipe she'll come up with, though – we can only hope that it will be edible, for the monkeys' sake.

It's also unclear how many monkeys will actually be participating in the upcoming battle, though the number of monkeys will surely be some positive integer. However, it's imperative that each of them receive a single smoothie, with all of the smoothies having been created using the same recipe as one another.

Of course, the number of available fruits is a serious limiting factor. If there are m monkeys, and some recipe R is chosen, then m × Ri fruits of each type i will be required in total, and this quantity cannot exceed Fi. However, there's an additional restriction – due to the high value placed on bananas, it's important that there be no leftover bananas, as they'd go to waste. Therefore, it must be the case that m × R1 = F1.

The Head Monkey has lots of great recipes in mind, but she's willing to accept that some of them might not work out in terms of producing a valid set of smoothies for 1 or more monkeys. That being said, she's wondering exactly how many different possible recipes she could validly choose. This quantity may be quite large, so she's only interested in its value when taken modulo 10,007.

As a hint, the following properties of modular arithmetic may be useful:

(A + B) mod M = ((A mod M) + (B mod M)) mod M
(A × B) mod M = ((A mod M) × (B mod M)) mod M

In test cases worth 2/12 of the points, N ≤ 3 and Fi ≤ 100 for each i.
In test cases worth another 3/12 of the points, Fi ≤ 100 for each i.
In test cases worth another 2/12 of the points, Fi ≤ 10,000 for each i.

Input Format

The first line of input consists of a single integer N.
The second line of input consists of N space-separated integers F1, …, FN.

Output Format

Output one line consisting of a single integer – the number of different possible recipes which might be used (modulo 10,007).

Sample Input

3
4 2 4
Sample Output

10
Sample Explanation

3 possible recipes are as follows:

R = [4, 1, 3] (serving 1 monkey)
R = [4, 2, 1] (serving 1 monkey)
R = [2, 1, 2] (serving 2 monkeys)
There are 7 other possible recipes.
*/


#include <bits/stdc++.h>
using namespace std;


bool good(int F[], int m, int N)
{
	for (int i = 1; i < N; i++)
	{
		if (F[i] < m)
			return false;
	}
	return true;
}





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int ans = 0;
	int F[101];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> F[i];
	}
	for (int i = 1; i <= sqrt(F[0]); i++)
	{
		int tmp_ans = 1;

		if ((F[0] % i == 0) && (good(F, i, N)))
		{
			
			for (int j = 1; j < N; j++)
			{
				tmp_ans = tmp_ans * (F[j] / i % 10007) % 10007;
			}
			
			ans += tmp_ans % 10007;
			if (F[0] / i != i)
			{
				tmp_ans = 1;

				for (int j = 1; j < N; j++)
				{
					tmp_ans = tmp_ans * (F[j] / (F[0] / i) % 10007) % 10007;
				}
				ans += tmp_ans % 10007;
			}
		}

	}






	cout << ans % 10007;



	return 0;
}

