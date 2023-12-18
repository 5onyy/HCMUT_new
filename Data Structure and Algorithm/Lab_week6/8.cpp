
#include<bits/stdc++.h>
    void dfs(int u, vector<int> & vis, vector<vector<int>>& edges){
        vis[u] = 1;
        for (int v : edges[u]) 
            if (!vis[v]) 
                dfs(v,vis,edges);
        return;
    }
int numberOfFriendGroups(vector<vector<int>>& edges) {
    int cnt = 0, n = (int)edges.size();
    vector<int> vis(n , 0);
    for (int i = 0; i < n; i++){
        if (!vis[i])    {dfs(i, vis, edges); cnt++;}
    }
    return cnt;
}