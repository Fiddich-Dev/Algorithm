#include <bits/stdc++.h>
using namespace std;

int r, c, t;

int a[54][54];
int b[54][54];

pair<int, int> air1;
pair<int, int> air2;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int dy1[] = {0, 1, 0, -1};
int dx1[] = {1, 0, -1, 0};

int ret;


void go(vector<pair<int, int>> v) {
    for(int i = v.size() - 1; i >= 1; i--) {
        a[v[i].first][v[i].second] = a[v[i-1].first][v[i-1].second];
    }
    a[v[0].first][v[0].second] = 0;
}

void spread() {

    fill(&b[0][0], &b[0][0] + 54 * 54, 0);

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            // a의 값이 -1아니고 0이 아닐떄
            if(a[i][j] != -1 && a[i][j] != 0) {

                int temp = a[i][j] / 5;
                b[i][j] += a[i][j];

                for(int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if(ny >= r || nx >= c || ny < 0 || nx < 0 || a[ny][nx] == -1) {
                        continue;
                    }
                    else {
                        b[ny][nx] += temp;
                        b[i][j] -= temp;
                    }
                }

            }

        }
    }


    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            a[i][j] = b[i][j];
        }
    }

    a[air1.first][air1.second] = -1;
    a[air2.first][air2.second] = -1;
}


void solve(int sy, int sx, int dy[], int dx[]) {
    vector<pair<int, int>> v;
    int y = sy;
    int x = sx;
    int cnt = 0;

    while(true) {
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];

        if(ny == sy && nx == sx) {
            break;
        }
        if(ny < 0 || nx < 0 || ny >= r || nx >= c) {
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if(ny == sy && nx == sx) {
            break;
        }
        y = ny;
        x = nx;
        v.push_back({y, x});
    }

    go(v);
}



int main() {
    cin >> r >> c >> t;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
            if(a[i][j] == -1) {
                air2.first = i;
                air2.second = j;
            }    
        }
    }

    air1.first = air2.first - 1;
    air1.second = air2.second;



    while(t--) {
        spread();
        solve(air1.first, air1.second, dy, dx);
        solve(air2.first, air2.second, dy1, dx1);
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ret += a[i][j];
        }
    }

    ret += 2;
    cout << ret << "\n";

}