#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int tempY, tempX;
int a[34][14];
int ret = 1e9;

bool check() {
    // 세로선
    for(int i = 0; i < n; i++) {
        int now = i;
        // 가로선
        for(int j = 0; j < h; j++) {
            if(a[j][now] == 1) {
                now++;
            }
            else if(now > 0 && a[j][now-1] == 1) {
                now--;
            }
        }

        if(now != i) {
            return false;
        }
    }
    return true;
}

void go(int now, int cnt) {
    if(cnt > 3 || cnt >= ret) {
        return;
    }
    if(check()) {
        ret = min(ret, cnt);
        return;
    }

    for(int i = now; i < h; i++) {
        for(int j = 0; j < n-1; j++) {
            if(a[i][j] == 1) {
                continue;
            }
            if(j > 0 && a[i][j-1] == 1) {
                continue;
            }
            if(a[i][j+1] == 1) {
                continue;
            }

            a[i][j] = 1;
            go(i, cnt+1);
            a[i][j] = 0;

        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for(int i = 0; i < m; i++) {
        cin >> tempY >> tempX;
        tempY--;
        tempX--;
        a[tempY][tempX] = 1;
    }

    
    go(0, 0);

    if(ret == 1e9) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
}