#include <bits/stdc++.h>
using namespace std;

int n, m;
// 주난
pair<int, int> p1;
// 범인
pair<int, int> p2;
char a[304][304];
string s;
int visited[304][304];

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;
    cin >> p1.first >> p1.second >> p2.first >> p2.second;
    p1.second--;
    p1.first--;
    p2.second--;
    p2.first--;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }

    visited[p1.first][p1.second] = 1;
    queue<pair<int, int>> q;
    
    q.push({p1});
    int cnt = 1;

    while(true) {
        cnt++;
        queue<pair<int, int>> qTemp;

        while(q.size()) {
            
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= n || nx >= m) {
                    continue;
                }
                if(visited[ny][nx] == 0 && a[ny][nx] == '0') {
                    q.push({ny, nx});
                    visited[ny][nx] = cnt;
                }
                if(visited[ny][nx] == 0 && a[ny][nx] != '0') {
                    qTemp.push({ny, nx});
                    visited[ny][nx] = cnt;
                }
            }
        }
        q = qTemp;

        if(visited[p2.first][p2.second] != 0) {
            break;
        }
    }

    cout << visited[p2.first][p2.second] - 1 << "\n";

    
}