#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
int m;
int a, b, c;
int dist[104][104];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);
    cin >> n;
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                cout << 0 << " ";
            }
            else if(dist[i][j] == INF) {
                cout << 0 << " ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}