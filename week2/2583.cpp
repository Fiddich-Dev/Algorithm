#include <bits/stdc++.h>
using namespace std;

int m, n, k;
int q, w, e, r;
int a[104][104];
int visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int ret;
int temp;
vector<int> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    temp++;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= m || nx >= n) {
            continue;
        }
        if(a[ny][nx] == 0 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

void bfs(int y, int x) {
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({y, x});

    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();
        temp++;

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= m || nx >= n) {
                continue;
            }
            if(a[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> q >> w >> e >> r;

        for(int j = w; j < r; j++) {
            for(int m = q; m < e; m++) {
                a[j][m] = 1;
            }
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 0 && !visited[i][j]) {
                temp = 0;
                bfs(i, j);
                ret++;
                v.push_back(temp);
            }
        }
    }

    cout << ret << "\n";
    sort(v.begin(), v.end());
    for(int i : v) {
        cout << i << " ";
    }
    cout << "\n";
}