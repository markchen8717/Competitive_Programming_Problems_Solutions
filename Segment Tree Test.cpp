/*
Segment Tree Test

http://wcipeg.com/problem/segtree

Perform the dynamic range minimum query.
Input

The first line of input will contain two space-separated integers: N (1 ≤ N ≤ 100 000), the number of elements in the array, and M (1 ≤ M ≤ 100 000), the number of operations to perform.

The next N lines each contain one non-negative integer less than 1 000 000. Specifically, line number i contains element i - 2 of the array. Note that the array has zero-based indexing.

The following M lines contain one operation each. Each operation is either of the form M i x, indicating that element number i (0 ≤ i < N) is to be changed to x (0 ≤ x < 1 000 000), or the form Q i j (0 ≤ i ≤ j < N) indicating that your program is to find the minimum value of the elements in the index range [i, j] (that is, inclusive) in the current state of the array and print this value to standard output.

Output

One integer, on its own line, for each Q statement: the answer to the query.
Sample Input

5 10
35232
390942
649675
224475
18709
Q 1 3
M 4 475689
Q 2 3
Q 1 3
Q 1 2
Q 3 3
Q 2 3
M 2 645514
M 2 680746
Q 0 4
Sample Output

224475
224475
224475
390942
224475
224475
35232
*/

#include "stdafx.h"
#include <bits/stdc++.h>
using namespace std;

//Struct of a node in the segment tree
struct node {
	int l;
	int r;
	int val;
};

void push_up(int nodeIdx, vector<node> &seg)
{
	seg[nodeIdx].val = min(seg[nodeIdx * 2].val, seg[nodeIdx * 2 + 1].val);
}

void build(int nodeIdx, int l, int r,vector<node> &seg, vector<int> &arr)
{
	seg[nodeIdx].l = l, seg[nodeIdx].r = r; //Assign the node's segments
	//Check if leaf node
	if (seg[nodeIdx].l == seg[nodeIdx].r)
	{
		//Assgin leaf nodes with values from the arr
		seg[nodeIdx].val = arr[seg[nodeIdx].l];		
	}
	else
	{
		//Build child nodes
		int mid = (l + r) / 2;
		build(nodeIdx * 2, l, mid, seg, arr);//Build left child node
		build(nodeIdx * 2 + 1, mid + 1, r, seg, arr); // Build right child node
		push_up(nodeIdx, seg);
	}


}
void update(int nodeIdx, int val, int idx,vector<node>&seg)
{
	if (seg[nodeIdx].l == seg[nodeIdx].r) //if node is a leaf node
	{
		//assgin the new value
		seg[nodeIdx].val = val;	
	}
	else
	{
		int mid = (seg[nodeIdx].l + seg[nodeIdx].r) / 2;
		
		if (idx <= mid)//search left child if idx is in left child range
			update(nodeIdx * 2, val, idx,seg);
		else 
			update(nodeIdx * 2+1, val, idx, seg); // search right child if idx is in right child range
		
		push_up(nodeIdx,seg);
	}

}

int query(int nodeIdx, int l, int r, vector<node>&seg)
{
	//if node segment is within the query range
	if (seg[nodeIdx].l >= l && seg[nodeIdx].r <= r)
	{
		return seg[nodeIdx].val;
	}
	//if node segment is completly out of the query range
	if (seg[nodeIdx].r< l || seg[nodeIdx].l > r)
	{
		return 1000001;
	}
	
	int ansL = query(nodeIdx * 2, l, r, seg);//answer of left child
	int ansR = query(nodeIdx * 2 + 1, l, r, seg);//answer of right child
	return min(ansL, ansR); //Return the min of ans of left and right child
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N>>Q;
	vector<int>input(N, 0);
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		input[i] = a;
	}
	vector <node> seg(4*N);
	build(1, 0, N-1, seg, input);

	for (int i = 0; i < Q; i++)
	{
		char a;
		int b, c;
		cin >> a >> b >> c;
		
		

		if (a == 'M')
			update(1, c, b, seg);
		else
			cout << query(1, b, c, seg)<<"\n";
			

	}
	


	return 0;
}

