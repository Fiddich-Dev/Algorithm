#include <bits/stdc++.h>
using namespace std;

int r, c;
int a[104][104];
int visited[104][104];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
vector<pair<int, int>> v;
int cnt, ret;

void dfs(int y, int x) {
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            continue;
        }
        // 1을 만나면 그걸 저장
        if(visited[ny][nx] == 0 && a[ny][nx] == 1) {
            visited[ny][nx] = 1;
            v.push_back({ny, nx});
        }
        if(visited[ny][nx] == 0 && a[ny][nx] == 0) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }


    while(true) {
        // visited 초기화
        memset(visited, 0, sizeof(visited));
        // 구멍뚫릴 치즈찾기
        dfs(0, 0);
        // 치즈가 없는지 확인
        if(v.empty()) {
            break;
        }
        // 1시간 후 시간
        ret++;
        // 구멍뚫린 치즈 없애기
        for(pair<int, int> p : v) {
            a[p.first][p.second] = 0;
        }
        cnt = v.size();
        v.clear();
    }

    cout << ret << "\n";
    cout << cnt << "\n";
}