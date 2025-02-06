#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
int a[104][104];
int visited[104][104];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};


void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(a[ny][nx] == 1 && visited[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}


int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = int(s[j] - '0');
        }
    }

    bfs(0, 0);
    cout << visited[n-1][m-1] << "\n";

}