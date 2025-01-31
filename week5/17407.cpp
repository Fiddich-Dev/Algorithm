#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int r, c, s;

int a[54][54];
int b[54][54];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int ret = 987654321;

struct A {
    int r;
    int c;
    int s;
};

vector<A> v;
vector<int> v_idx;

int count(int b[54][54]) {
    int z = 987654321;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += b[i][j];
        }
        z = min(z, sum);
    }
    return z;
}

void solve(A temp) {
    for(int i = 0; i < temp.s; i++) {
        vector<int> value;
        vector<pair<int, int>> idx;
        int sy = temp.r - (i+1);
        int sx = temp.c - (i+1);
        int ey = temp.r + (i+1);
        int ex = temp.c + (i+1);
        value.push_back(b[sy][sx]);
        idx.push_back({sy, sx});

        int y = sy;
        int x = sx;
        int flag = 0;

        while(true) {
            int ny = y + dy[flag];
            int nx = x + dx[flag];

            if(ny == sy && nx == sx) {
                break;
            }

            if(ny < sy || nx < sx || ny > ey || nx > ex) {
                flag = (flag + 1) % 4;
                ny = y + dy[flag];
                nx = x + dx[flag];
            }

            value.push_back(b[ny][nx]);
            idx.push_back({ny, nx});
            y = ny;
            x = nx;
        }

        rotate(value.begin(), value.end() - 1, value.end());

        for(int j = 0; j < value.size(); j++) {
            b[idx[j].first][idx[j].second] = value[j];
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        r--;
        c--;
        v.push_back({r, c, s});
        v_idx.push_back(i);
    }

    do {
        memcpy(b, a, sizeof(b));
        for(int i : v_idx) {
            solve(v[i]);
        }
        ret = min(ret, count(b));

    } while(next_permutation(v_idx.begin(), v_idx.end()));

    cout << ret << "\n";
}