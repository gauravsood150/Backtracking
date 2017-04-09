#include <iostream>

using namespace std;

bool solveMaze(int** maze, int nrow, int ncol, int row, int col)
{
	if(row==nrow-1 && col==ncol-1)
	{
		maze[row][col]=2;
		return true;
	}

	if(row<0 || col<0 || row>=nrow || col>=ncol || maze[row][col]!=1)
		return 0;

	int oldValue=maze[row][col];
	maze[row][col]=2;

	if(solveMaze(maze,nrow,ncol,row+1,col))
		return true;
	if(solveMaze(maze,nrow,ncol,row,col+1))
		return true;
	if(solveMaze(maze,nrow,ncol,row-1,col))
		return true;
	if(solveMaze(maze,nrow,ncol,row,col-1))
		return true;
	maze[row][col]=oldValue;
	return false;
}

void printMaze(int **maze, int nrow, int ncol)
{
	for(int i=0; i<nrow; i++)
	{
		for (int j=0; j<ncol; ++j)
			cout<<maze[i][j]<<" ";
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int nrow,ncol;
	cin>>nrow>>ncol;
	int **maze;
	maze =new int*[nrow];
	for(int i=0; i<nrow; ++i)
	{
		maze[i]=new int[ncol];
	}
	for(int i=0; i<nrow; i++)
		for (int j=0; j<ncol; ++j)
			cin>>maze[i][j];
	cout<<endl;
	
	if(solveMaze((int**)maze, nrow, ncol, 0, 0)==true)
		printMaze((int**) maze, nrow, ncol);
	else
		cout<<"NO VALID PATH";

	return 0;
}