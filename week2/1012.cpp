#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, k;
int a[54][54];
int visited[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int temp1, temp2;
int ret;


void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
            continue;
        }
        if(a[ny][nx] == 1 && visited[ny][nx] == 0) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    
    for(int q = 0; q < t; q++) {
        // 배열 비우기
        ret = 0;
        fill(&a[0][0], &a[0][0] + 54*54, 0);
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);

        cin >> m >> n >> k;

        for(int i = 0; i < k; i++) {
            cin >> temp1 >> temp2;
            a[temp2][temp1] = 1;
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << "\n";
    }
}