/*
https://dmoj.ca/problem/ccc10j5

CCC '10 J5 - Knight Hop
Canadian Computing Competition: 2010 Stage 1, Junior #5

Below is an 8×88×8 chessboard on which we will designate square locations using the ordered pairs as indicated. For example, notice that piece AA is at position (2,2)(2,2) and piece BB is at position (4,3)(4,3).


A knight is a special game piece that can leap over other pieces, moving in the "L" pattern. Specifically, in the diagram below, KK represents the knight's starting position and the numbers 1 through 8 represent possible places the knight may move to.


Your program will read the starting location of the knight and output the smallest number of jumps or moves needed to arrive at a location specified in the second input.

Input Specification

Your program will read four integers, where each integer is in the range 1…81…8. The first two integers represent the starting position of the knight. The second two integers represent the final position of the knight.

Output Specification

Your program should output the minimum (non-negative integer) number of moves required to move the knight from the starting position to the final position. Note that the knight is not allowed to move off the board during the sequence of moves.

Sample Input 1

Copy
2 1
3 3
Output for Sample Input 1

Copy
1
Sample Input 2

Copy
4 2
7 5
Output for Sample Input 2

Copy
2

*/
#include <iostream>

#include <bits/stdc++.h>
using namespace std;



void dfs(int x, int y, vector<vector<int>> & board, int d)
{
	board[x][y] = d;

	if (x + 1 <= 8 && y + 2 <= 8)
	{
		int newx = x + 1;
		int newy = y + 2;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}

	if (x + 2 <= 8 && y + 1 <= 8)
	{
		int newx = x + 2;
		int newy = y + 1;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}

	if (x + 2 <= 8 && y - 1 >0)
	{
		int newx = x + 2;
		int newy = y - 1;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}

	if (x + 1 <= 8 && y - 2 >  0)
	{
		int newx = x + 1;
		int newy = y - 2;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}

	if (x - 2 >0 && y - 1 >0)
	{
		int newx = x - 2;
		int newy = y - 1;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}

	if (x - 1 >0 && y - 2 > 0)
	{
		int newx = x - 1;
		int newy = y - 2;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}

	if (x - 2 >0 && y + 1 <= 8)
	{
		int newx = x - 2;
		int newy = y + 1;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}
	if (x - 1 > 0 && y + 2 <= 8)
	{
		int newx = x - 1;
		int newy = y + 2;
		if ((board[newx][newy] == 0) || (board[newx][newy] > d + 1))
			dfs(newx, newy, board, d + 1);
	}
}






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sx, sy, dx, dy;
	cin >> sx;
	cin >> sy;
	cin >> dx;
	cin >> dy;



	vector<vector<int>> board(9, vector<int>(9, 0));




	dfs(sx, sy, board, 0);
	cout << board[dx][dy];



}
