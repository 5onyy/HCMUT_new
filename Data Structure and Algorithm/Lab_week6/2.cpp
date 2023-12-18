#include<bits/stdc++.h>
class Graph
{
private:
	int V;
	Adjacency *adj;
    vector<int> vis;
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
	Adjacency *DFS(int v)
    {
        Adjacency* ans = new Adjacency(1);
        vis.assign(V,0);
        // v is a vertex we start BFS
        dfs(ans,v);
        return ans;
	}
	void dfs(Adjacency*& ans, int v){
	    vis[v] = 1; 
        ans -> push(v);
        for (int i = 0; i < adj[v].getSize(); i++){
            int vv = adj[v].getElement(i);
            if (!vis[vv]) dfs(ans,vv);
        }
	}
};