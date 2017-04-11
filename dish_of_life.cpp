#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  int t,n,k,a;
  cin>>t;
  while(t)
  {
    cin>>n>>k;
    vector<vector<int> > p;
    int d,x;
    for(int i=0; i<n, i++)
    {
      cin>>d;
      p[i].push_back(d);
      for(int j=0; j<d; j++)
      {
        cin>>x;
        p[i].push_back(x);
      }
    }
    sort()
    t--;
  }
}
