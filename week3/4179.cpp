#include <bits/stdc++.h>
using namespace std;

int r, c;
char a[1004][1004];
int visited[1004][1004];
int visited2[1004][1004];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
string s;

// 지훈 위치
pair<int, int> p;
// 불 위치
vector<pair<int, int>> v;
int ret = 1e9;

// 지훈이 움직이는 거
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

            if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
                continue;
            }
            if(visited[ny][nx] == 0 && a[ny][nx] == '.') {
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}


int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++) {
        cin >> s;
        for(int j = 0; j < c; j++) {
            a[i][j] = s[j];
            if(s[j] == 'J') {
                p = {i, j};
            }
            else if(s[j] == 'F') {
                v.push_back({i, j});
            }
        }
    }

    bfs(p.first, p.second);


    queue<pair<int, int>> q;
    for(pair<int, int> temp : v) {
        q.push(temp);
        visited2[temp.first][temp.second] = 1;
    }

    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
                continue;
            }
            if(visited2[ny][nx] == 0 && a[ny][nx] == '.') {
                q.push({ny, nx});
                visited2[ny][nx] = visited2[y][x] + 1;
            }

        }
    }


    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            // 가장자리 중에
            if(i == 0 || j == 0 || i == r-1 || j == c-1) {
                // 지훈이가 갈 수 있는 곳 중에
                if(visited[i][j] != 0) {
                    // 지훈이가 불보다 빨리 도착하거나
                    // 불이 안올떄
                    if(visited[i][j] < visited2[i][j] || visited2[i][j] == 0) {
                        ret = min(ret, visited[i][j]);
                    }
                }
            }
        }
    }

    if(ret == 1e9) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << ret << "\n";
    }
}