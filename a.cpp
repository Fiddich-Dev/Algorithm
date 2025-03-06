#include <bits/stdc++.h>
using namespace std;


int V, E;
int k;
int u, v, w;

const int INF = 1e9;
vector<pair<int, int>> adj[20004];
vector<int> dist(20004, INF);

 void dijkstra(int start) {
    priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while(pq.size()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(dist[u] != here_cost) {
            continue;
        }

        for(auto there : adj[u]) {
            int new_cost = here_cost + there.first;
            if(new_cost < dist[there.second]) {
                dist[there.second] = new_cost;
                pq.push({new_cost, there.second});
            }
        }
    }
 }

 
 int main() {
    cin >> V >> E;
    cin >> k;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    dijkstra(1);
    
    for(int i = 0; i < V; i++) {
        if(dist[i+1] == INF) {
            cout << "INF\n";
            continue;
        }
        cout << dist[i+1] << "\n";
    }
}