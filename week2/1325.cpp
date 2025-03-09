#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b;
vector<int> adj[10004];
int visited[10004];
vector<pair<int, int>> ret;
int mx;


int dfs(int here) {
    visited[here] = 1;
    int cnt = 1;

    for(int there : adj[here]) {
        
        if(visited[there] == 0) {
            cnt += dfs(there);
        }
    }
    return cnt;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        int temp = dfs(i);
        mx = max(mx, temp);
        ret.push_back({i, temp});
    }

    for(pair<int, int> p : ret) {
        if(p.second == mx) {
            cout << p.first << "\n";
        }
    }
    
}