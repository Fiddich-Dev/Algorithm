#include <bits/stdc++.h>
using namespace std;

int n, m, c;
int a[54][54];
int tempY, tempX;
int dp[54][54][54][54];

int go(int y, int x, int cnt, int pre) {

    if(cnt < 0) {
        return 0;
    }

    if(y == n-1 && x == m-1) {
        if(cnt == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    int &ret = dp[y][x][cnt][pre];
    if(ret != -1) {
        return ret;
    }

    int temp1 = 0;
    int temp2 = 0;
    if(y+1 < n) {
        // 오락실이 있을떄
        if(a[y+1][x] != 0) {
            // 오락실 번호가 이전 오락실 번호보다 클떄
            if(a[y+1][x] > pre) {
                temp1 = go(y+1, x, cnt-1, a[y+1][x]);
            }
        }
        // 오락실이 없을떄
        else {
            temp1 = go(y+1, x, cnt, pre);
        }
    }

    if(x+1 < m) {
        // 오락실이 있을떄
        if(a[y][x+1] != 0) {
            // 오락실 번호가 이전 오락실 번호보다 클떄
            if(a[y][x+1] > pre) {
                temp2 = go(y, x+1, cnt-1, a[y][x+1]);
            }
        }
        // 오락실이 없을떄
        else {
            temp2 = go(y, x+1, cnt, pre);
        }
    }

    return ret = (temp1 + temp2) % 1000007;

}

int main() {
    cin >> n >> m >> c;

    memset(dp, -1, sizeof(dp));
    
    for(int i = 1; i <= c; i++) {
        cin >> tempY >> tempX;
        a[tempY-1][tempX-1] = i;
    }


    for(int i = 0; i <= c; i++) {
        // (0, 0)에 오락실이 없을때
        if(a[0][0] == 0) {
            cout << go(0, 0, i, 0) << " ";
        }
        // (0, 0)에 오락실이 있을때
        else {
            cout << go(0, 0, i-1, a[0][0]) << " ";
        }
    }


    cout << "\n";

}

// 테이블 : dp[y][x][앞으로 방문해야하는 오락실 수][이전에 방문했던 오락실 번호] = 현재지점까지 가능한 경우의 수
// 점화식 : dp[y][x][앞으로 방문해야하는 오락실 수][이전에 방문했던 오락실 번호] = dp[y+1][x][앞으로 방문해야하는 오락실 수][이전에 방문했던 오락실 번호] + dp[y][x+1][앞으로 방문해야하는 오락실 수][이전에 방문했던 오락실 번호]
// 초기화 : 