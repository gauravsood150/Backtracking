#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
	vector<vector<int> > G;
	int v;
public:
	Graph(int );
	void addEdage(int, int);
	bool m_colouring(int);
	bool m_colouringUtil(vector<int > & , int, int);
	bool checkColor(vector<int > & , int, int);
};

Graph::Graph(int v)
{
	this->v=v;
	G.resize(v);
}

void Graph::addEdage(int v, int u)
{
	G[v].push_back(u);
	G[u].push_back(v);
}

bool Graph::checkColor(vector<int> &color,int i, int j)
{
	for(vector<int>::iterator k=G[j].begin(); k!=G[j].end(); k++)
		{
			if(color[*k]==i)
			{
				return false;
			}
		}
	return true;
}

bool Graph::m_colouringUtil(vector<int> &color, int j, int m)
{
	if(j>=v) return true;
		
	for(int i=1; i<m+1; i++)
	{
		if(checkColor(color,i,j)==true)
		{	
			color[j]=i;
			if(m_colouringUtil(color, j+1, m)) return true;
			color[j]=0;
		}
	}
	return false;
}

bool Graph::m_colouring( int m)
{
	vector<int > color(v);
	if( m_colouringUtil(color, 0,m))
		{
		for(int i = 0; i < v; ++i)
			cout<<color[i]<<" ";
		return true;
		}
	return false;
}

int main()
{
	Graph graph(4);
	graph.addEdage(0,1);
	graph.addEdage(0,2);
	graph.addEdage(0,3);
	graph.addEdage(2,1);
	graph.addEdage(2,3);
	graph.m_colouring(5);
	return 0;
}