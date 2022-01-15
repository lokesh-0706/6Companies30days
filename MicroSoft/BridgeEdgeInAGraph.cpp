#include<bits/stdc++.h>
using namespace std;
void dfs(int src,vector<bool>&visited,vector<int> adj_list[],int c,int d)
	{
		visited[src] = true;
		for(auto i:adj_list[src])
		{
		    if((src==c && i==d)||(src==d && i==c))
		        continue;
		    if(!visited[i])
		        dfs(i,visited,adj_list,c,d);
		}
		
	}
	
   int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>visited(V,false);
        dfs(c,visited,adj,c,d);
        
        if(!visited[d])
            return 1;
        return 0;
    }


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
    	cout << isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}
