// DMPG '17 B3 - Heroes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long int N;
	long int hF;
	long  int hD;

	cin >> N >> hF >> hD;
	long   int fF;
	long  int fD;
	long  int temphF;
	

	for (long int i = 0; i < N; i++)
	{
		
		
		temphF = hF;
		cin >> fF >> fD;
		
		long int j = 1;
		while (true)
		{
			
			fF -= hD;
			if (fF <= 0)
				break;
			if (j % 4 != 0)
			{
				temphF -= fD;
				if (temphF <= 0)
					break;
			}

			
			j++;
		}
		
		if (temphF <= 0)
			cout << "Lose " << j << "\n";
		else
			cout << "Win " << j << "\n" ;
	}


    
}
