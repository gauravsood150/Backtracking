#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int> > &board, int n, int row, int col )
{
	for (int i = 0; i < row; ++i)				//to check upper rows
		if(board[i][col]==1) return false;

	int temp1=row-1, temp2=col-1;				//to check upper left side diagonal
	while(temp1>=0 && temp2>=0)
	{
		if(board[temp1][temp2]==1) return false;
		temp1--; temp2--;
	}
	
	temp1=row-1; temp2=col+1;					//to check upper right side diagonal
	while(temp1>=0 && temp2<n)
	{
		if(board[temp1][temp2]==1) return false;
		temp1--; temp2++;
	}
	return true;
}

bool fillQueens(vector<vector<int> > &board, int n, int row)
{
	if(row>=n) return true;

	for(int col=0; col<n; col++)
	{
		if(isSafe(board, n, row, col))
		{
			board[row][col]=1;
	
			if(fillQueens(board, n, row+1)==true)
				return true;
			
			board[row][col]=0;
		}
	}
	return false;
}

void printBoard(vector<vector<int> > &board, int n)
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

void N_Queens(int n)
{
	vector<vector<int> > board(n,vector<int> (n));
	if(fillQueens(board, n, 0)==true)
		printBoard(board,n);
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	N_Queens(n);
	return 0;
}