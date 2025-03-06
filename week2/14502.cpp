#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10][10];
int visited[10][10];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int cnt;

// 바이러스 위치
vector<pair<int, int>> v1;
// 빈칸 위치
vector<pair<int, int>> v2;

int ret = -987654321;

// 벽 개수
int w;

int bfs(int y, int x) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({y, x});
    cnt++;

    while(q.size()) {
        tie(y, x) = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                continue;
            }
            if(visited[ny][nx] == 0 && a[ny][nx] == 0) {
                q.push({ny, nx});
                cnt++;
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
    return cnt;
}

int dfs(int y, int x) {
    visited[y][x] = 1;
    int temp = 1;

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
            continue;
        }
        if(visited[ny][nx] == 0 && a[ny][nx] == 0) {
            temp += dfs(ny, nx);
        }
    }
    return temp;
}

void combi(int start, vector<pair<int, int>> b) {
    if(b.size() == 3) {
        memset(visited, 0, sizeof(visited));
        // 벽 세우기
        for(int i = 0; i < 3; i++) {
            a[b[i].first][b[i].second] = 1;
        }
        int sum = 0;
        for(int i = 0; i < v1.size(); i++) {
            sum += bfs(v1[i].first, v1[i].second);
        }
        ret = max(ret, n * m - w - sum - 3);

        // 벽 없애기
        for(int i = 0; i < 3; i++) {
            a[b[i].first][b[i].second] = 0;
        }
        return;
    }
    for(int i = start+1; i < v2.size(); i++) {
        b.push_back(v2[i]);
        combi(i, b);
        b.pop_back();
    }
}





int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) {
                v1.push_back({i, j});
            }
            else if(a[i][j] == 0) {
                v2.push_back({i, j});
            }
            else {
                w++;
            }
        }
    }

    // for(int i = 0; i < v2.size(); i++) {
    //     for(int j = i+1; j < v2.size(); j++) {
    //         for(int k = j+1; k < v2.size(); k++) {
    //             fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    //             cnt = 0;
    //             // 벽 세우기
    //             a[v2[i].first][v2[i].second] = 1;
    //             a[v2[j].first][v2[j].second] = 1;
    //             a[v2[k].first][v2[k].second] = 1;
    //             // 바이러스 퍼트리기
    //             int sum = 0;
    //             for(pair<int, int> p : v1) {
    //                 sum += dfs(p.first, p.second);
    //             }
    //             // cnt가 퍼진 바이러스의 수
    //             ret = max(ret, n * m - w - 3 - sum);

    //             // 벽 없애기
    //             a[v2[i].first][v2[i].second] = 0;
    //             a[v2[j].first][v2[j].second] = 0;
    //             a[v2[k].first][v2[k].second] = 0;
    //         }
    //     }
    // }
    vector<pair<int, int>> b;
    combi(-1, b);

    cout << ret << "\n";
}