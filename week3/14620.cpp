#include <bits/stdc++.h>
using namespace std;

int n;
int a[14][14];
int visited[14][14];
int ret = 1e9;

bool check(int y, int x) {
    if(visited[y][x] == 1 || visited[y-1][x] == 1 || visited[y][x-1] == 1 || visited[y+1][x] == 1 || visited[y][x+1] == 1) {
        return false;
    }
    return true;

}

void go(int now, vector<pair<int, int>> b) {
    if(b.size() == 3) {
        int sum = 0;

        for(pair<int, int> p : b) {
            sum += a[p.first][p.second];
            sum += a[p.first-1][p.second];
            sum += a[p.first][p.second-1];
            sum += a[p.first+1][p.second];
            sum += a[p.first][p.second+1];
        }
        ret = min(ret, sum);
        return;
    }

    for(int i = now; i < n-1; i++) {
        for(int j = 1; j < n-1; j++) {
            if(check(i, j) == true) {
                visited[i][j] = 1;
                visited[i-1][j] = 1;
                visited[i][j-1] = 1;
                visited[i+1][j] = 1;
                visited[i][j+1] = 1;
                b.push_back({i, j});

                go(i, b);

                visited[i][j] = 0;
                visited[i-1][j] = 0;
                visited[i][j-1] = 0;
                visited[i+1][j] = 0;
                visited[i][j+1] = 0;
                b.pop_back();
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<pair<int, int>> v;
    go(1, v);

    cout << ret << "\n";
}