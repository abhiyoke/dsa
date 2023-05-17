#include <bits/stdc++.h>
using namespace std;


    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        cout<<node<<" ";
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

   



int main() {
  
   
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
     
       vector<int>vis(V,0);
        int count=0;
        for(int i=0;i<V;i++){
        	if(!vis[i]){
         dfs(i, adj,vis);
         count++;
         }
         }
         cout<<endl;
         cout<<count;
        
    return 0;
}
