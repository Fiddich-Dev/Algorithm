#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int V, E;
int k;
int u, v, w;
// []지점에서 second로 가는 코스트가 first
vector<pair<int, int>> adj[20004];
vector<int> dist;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    cin >> k;
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    dist.resize(20004, INF);

    dist[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});
    
    while(pq.size()) {
        int here_cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] != here_cost) {
            continue;
        }

        for(pair<int, int> there : adj[here]) {
            int new_cost = here_cost + there.first;
            if(dist[there.second] > new_cost) {
                dist[there.second] = new_cost;
                pq.push({dist[there.second], there.second});
            }
        }
    }

    for(int i = 0; i < V; i++) {
        if(dist[i+1] == INF) {
            cout << "INF\n";
        }
        else {
            cout << dist[i+1] << "\n";
        }
    }
}