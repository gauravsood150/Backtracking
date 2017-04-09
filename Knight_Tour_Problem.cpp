
#include <iostream>
#include <vector>

using namespace std;

bool fillboard(vector<vector<int> > &board, int n, int row, int col, int step)
{
	if(step == n*n+1) return true;

	if(row<0 || col<0 || row>=n || col>=n || board[row][col]!=0) return false;

	board[row][col]=step;

	if(fillboard(board,n,row+1,col+2,step+1)==true)
		return true;
	if(fillboard(board,n,row-1,col+2,step+1)==true)
		return true;
	if(fillboard(board,n,row+2,col+1,step+1)==true)
		return true;
	if(fillboard(board,n,row+2,col-1,step+1)==true)
		return true;
	if(fillboard(board,n,row+1,col-2,step+1)==true)
		return true;
	if(fillboard(board,n,row-1,col-2,step+1)==true)
		return true;
	if(fillboard(board,n,row-2,col+1,step+1)==true)
		return true;
	if(fillboard(board,n,row-2,col-1,step+1)==true)
		return true;

	board[row][col]=0;
	return false;
}

void printboard(vector<vector<int> > &board, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<board[i][j]<<"	";
		}
		cout<<endl;
	}
}

bool solveKT(int n)
{
	vector<vector<int> > board(n,vector<int> (n));
	if(fillboard(board, n, 0, 0, 1)==false)
		return false;
	printboard(board,n);
	return true;
}

int main()
{
	int n;
	cin>>n;

	solveKT(n);
	return 0;
}
