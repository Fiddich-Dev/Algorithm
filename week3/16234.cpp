#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[54][54];
int visited[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int ret;
int sum;
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    sum += a[y][x];
    v.push_back({y, x});

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= n || nx >= n) {
            continue;
        }
        if(visited[ny][nx] == 0 && abs(a[y][x] - a[ny][nx]) >= l && abs(a[y][x] - a[ny][nx]) <= r) {
            dfs(ny, nx);
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // dfs가 n*n번 호출되면 멈춤

    while(true) {
        fill(&visited[0][0], &visited[0][0] + 54*54, 0);
        int cnt = 0;


        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0) {
                    sum = 0;
                    v.clear();

                    dfs(i, j);
                    cnt++;

                    int temp = sum / v.size();
                    for(pair<int, int> p : v) {
                        a[p.first][p.second] = temp;
                    }
                }
            }
        }


        if(cnt == n*n) {
            break;
        }
        ret++;
    }

    cout << ret << "\n";

}