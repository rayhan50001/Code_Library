#include <bits/stdc++.h>
using namespace std;
int N;
struct Edge
{
	int src, dest;
};
class Graph
{
public:
	vector<int> adjList[1000];
	Graph(vector<Edge> edges)
	{
		for(unsigned i = 0; i < edges.size(); i++)
		{
			int src = edges[i].src;
			int dest = edges[i].dest;

			adjList[src].push_back(dest);
			adjList[dest].push_back(src);
		}
	}
};

void printAllHamiltonianPaths(Graph g, int v,
	vector<bool> visited, vector<int> &path)
{
	if (path.size() == N)
	{
	    cout<<"yes\n";
		// print hamiltonian path
		for (int i : path)
			cout << i+1 << " ";

		int f=0;
		for(int i=1; i<path.size(); i++)
        {
            int s=path[i]+path[i-1]+2;
            int sq=sqrt(s);
            if(sq*sq!=s)f=1;
        }
        if(f==1)cout<<"No\n";
        else cout<<"Yes\n";
        cout << endl;
		return;
	}

	// Check if every edge starting from vertex v leads
	// to a solution or not
	if(g.adjList[v].size())
    {
    //cout<<"yes\n";
	for (int w : g.adjList[v])
	{
		if (!visited[w])
		{
			visited[w] = true;
			path.push_back(w);
			printAllHamiltonianPaths(g, w, visited, path);
		}
	}
	}
	else return;
}

int main()
{
	vector<Edge> edges;
	cin>>N;
	for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(i!=j)
            {
                int sq=sqrt(i+j);
                if(sq*sq==i+j)
                {
                    cout<<i<<" "<<j<<endl;
                    edges.push_back({i,j});
                }
            }
        }
    }
	int start = 0;
	Graph g(edges);
	for(int i=1; i<=N; i++)
    {
    vector<int> path;
    start=i;
	path.push_back(start);
	vector<bool> visited(N+1);
	visited[start] = true;
	printAllHamiltonianPaths(g, start, visited, path);
	cout<<start<<endl;
	cout<<"start\n"<<endl;
	}

	return 0;
}
