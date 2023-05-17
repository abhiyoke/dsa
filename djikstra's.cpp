#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> shortestPaths(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges) {
        adj[it[0]].push_back({ it[1], it[2] });
        adj[it[1]].push_back({ it[0], it[2] });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    dist[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({ dis + edW, adjNode });
                parent[adjNode] = node;
            }
        }
    }

    vector<vector<int>> shortestPaths;
    for (int i = 2; i <= n; i++) {
        if (dist[i] == 1e9) {
            shortestPaths.push_back({ -1 }); // No path from source to vertex i
        } else {
            vector<int> path;
            int node = i;

            while (parent[node] != node) {
                path.push_back(node);
                node = parent[node];
            }
            path.push_back(1);

            reverse(path.begin(), path.end());
            shortestPaths.push_back(path);
        }
    }
    return shortestPaths;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i].push_back(u);
        edges[i].push_back(v);
        edges[i].push_back(w);
    }

    vector<vector<int>> paths = shortestPaths(V, E, edges);

    for (int i = 0; i < paths.size(); i++) {
        cout << "Shortest path from 1 to " << i + 2 << ": ";
        vector<int> path = paths[i];

        if (path[0] == -1) {
            cout << "No path" << endl;
        } else {
            for (int j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j != path.size() - 1)
                    cout << " -> ";
            }
            cout << endl;
        }
    }

    return 0;
}
