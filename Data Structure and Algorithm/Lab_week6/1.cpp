#include<bits/stdc++.h>
class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        Adjacency *ans = new Adjacency(1);
        queue<int> q;
        q.push(v);
        vector<int> vis(V,0);
        vis[v] = 1;
        while ((int)q.size()){
            int u = q.front();  q.pop();
            ans -> push(u);
            for (int i = 0; i < adj[u].getSize(); i++){
                int v = adj[u].getElement(i);
                if (vis[v])  continue;
                vis[v] = 1; 
                q.push(v);
            }
        }
        return ans;
	}
};