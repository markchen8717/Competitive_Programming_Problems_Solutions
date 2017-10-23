/*

DMOPC '16 Contest 4 P1 - Fast Exponents

https://dmoj.ca/problem/dmopc16c4p1

Molly's teacher assigned her very tedious homework:

Given an integer iiii, find out if it's a power of two or not

Molly asks Andrew, but he would much rather play Geometry Dash, so he decides to enslave ask you to do it instead!

Input Specification

The first line will contain a single integer, NN.
Lines 2…N+12…N+1 will each contain an integer, iiii.

Output Specification

For each of the NN integers, output T if they are a power of 22, otherwise output F

Constraints

1≤N≤1061≤N≤106
1≤ii<2631≤ii<263

Sample Input

Copy
2
1
3
Sample Output

Copy
T
F

*/
#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
 long long lines, input;
	cin>>lines;

	for (unsigned int i = 0; i < lines; i ++) // repeat this program for the amount of lines
	{
	    cin>>input;
        while ((input % 2 == 0) && (input > 1))
        {   
		    input /= 2 ;
		 
		}
		if (input == 1)
		{
		    cout<<"T\n";
		}
		else 
		{
		    cout<<"F\n";
		}
	input = 0;
	
	}
return 0;
}
