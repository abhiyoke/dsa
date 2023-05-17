#include <bits/stdc++.h>
using namespace std;
    void bfs(vector<int> adj[],vector<int>&vis,int node) {
       
        vis[node] = 1; 
        queue<int> q;
     
        q.push(node); 
        vector<int> bfs; 
      
        while(!q.empty()) {
        
            int node = q.front(); 
            cout<<node<<" ";
            q.pop(); 
           
           
            for(auto it : adj[node]) {
               
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
       
    }



int main() 
{
int n,m;
cin>>n>>m;
 vector <int> adj[n];

for(int j=0;j<m;j++){
int u,v;
cin>>u>>v;
adj[u].push_back(v);
adj[v].push_back(u);
}
  
    
   // addEdge(adj, 0, 1);
   // addEdge(adj, 1, 2);
   // addEdge(adj, 1, 3);
   // addEdge(adj, 0, 4);

  vector<int>vis(n,0);
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            count++;
            bfs(adj, vis, i);
        }
    }
    cout<<endl;
    cout<<count;

    return 0;
}
