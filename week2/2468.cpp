#include <bits/stdc++.h>
using namespace std;

int n;
int a[104][104];
int visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int m;
int ret = 1;


void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
            continue;
        }
        if(a[ny][nx] > 0 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }
}

void bfs(int y, int x) {
    visited[y][x] = 0;
    queue<pair<int, int>> q;
    q.push({y, x});

    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
                continue;
            }
            if(a[ny][nx] > 0 && !visited[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

}

void rain() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j]--;
        }
    }
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            m = max(m, a[i][j]);
        }
    }

    for(int i = 0; i < m; i++) {
        // 초기화
        int temp = 0;
        fill(&visited[0][0], &visited[0][0] + 104*104, 0);

        // 커넥티드 컴포넌트 검사
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(a[j][k] > 0 && !visited[j][k]) {
                    dfs(j, k);
                    temp++;
                }
            }
        }

        ret = max(ret, temp);

        // 비 내리기
        rain();

    }

    cout << ret << "\n";

}