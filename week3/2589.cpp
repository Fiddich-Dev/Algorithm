#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[54][54];
int visited[54][54];
string s;
int ret = -1e9;
// 땅위치
vector<pair<int, int>> v;

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
            if(visited[ny][nx] == 0 && a[ny][nx] == 'L') {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
                ret = max(ret, visited[ny][nx]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if(a[i][j] == 'L') {
                v.push_back({i, j});
            }
        }
    }

    for(pair<int, int> p : v) {
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        bfs(p.first, p.second);
    }

    cout << ret-1 << '\n';
}