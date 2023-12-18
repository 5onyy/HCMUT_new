// Some helping functions
#include<bits/stdc++.h>
#define ii pair<int,int>
int Dijkstra(int** graph, int src, int dst) {
	// TODO: return the length of shortest path from src to dst.
	vector<int> d(1000000,99999);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	d[src] = 0;
	pq.push({0,src});
    int n = 6;
	while (!pq.empty()){
	    ii uu = pq.top();   pq.pop();
	    int u = uu.second;
	    for (int i = 0; i < n; i++){
	        if (!graph[u][i]) continue;
	        int w = graph[u][i];
	        if (d[i] > d[u] + w){
	            d[i] = d[u] + w;
	            pq.push({d[i],i});
	        }
	    }
	}
	return d[dst];
	
	return 0;
    
}
