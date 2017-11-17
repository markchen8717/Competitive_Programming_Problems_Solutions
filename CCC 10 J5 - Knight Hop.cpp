#include "stdafx.h"
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