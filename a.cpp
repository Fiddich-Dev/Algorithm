#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
int n, m;
int a, b, c;
vector<pair<int, int>> adj[504];
vector<ll> dist;

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    dist.resize(n+1, INF);
    dist[1] = 0;
    queue<int> q;

    for(int i = 0; i < n; i++) {
        for(int here = 1; here <= n; here++) {
            for(pair<int, int> there : adj[here]) {
                if(dist[here] != INF && dist[there.second] > dist[here] + there.first) {
                    // n번쨰에도 완화가 일어나면 순환이 있음
                    if(i == n-1) {
                        // cout << here << " : " << there.second << "\n";
                        q.push(here);
                    }
                    dist[there.second] = dist[here] + there.first;
                }
            }
        }
    }

    if(q.size()) {
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 2; i <= n; i++) {
        if(dist[i] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << dist[i] << "\n";
        }
    }

}