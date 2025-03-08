#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a, b, c;
const int INF = 987654321;
ll dist[504];
ll visited[504];
vector<pair<int, int>> adj[504];

int main() {

    fill(dist, dist + 504, INF); 
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }

    dist[0] = 0;
    queue<int> q;

    for(int i = 0; i < n; i++) {
        for(int here = 0; here < n; here++) {
            for(pair<int, int> there : adj[here]) {
                int d = there.second;
                int to = there.first;
                if(dist[here] != INF && dist[here] + d < dist[to]) {
                    if(i == n-1) {
                        q.push(to);
                    }
                    dist[to] = dist[here] + d;
                }
            }
        }
    }

    if(q.size()) {
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 1; i < n; i++) {
        if(dist[i] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }
}