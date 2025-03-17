#include <bits/stdc++.h>
using namespace std;

int n;
int mp, mf, ms, mv;
// int p, f, s, v, c;
int ret = 987654321;
vector<int> ret2;

int a[18][6];

bool check(int q, int w, int e, int r) {
    if(q >= mp && w >= mf && e >= ms && r >= mv) {
        return true;
    }
    return false;
}

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
    }

    for(int i = 0; i <= (1 << n) - 1; i++) {
        int q = 0;
        int w = 0;
        int e = 0;
        int r = 0;
        int c = 0;
        vector<int> v;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                q += a[j][0];
                w += a[j][1];
                e += a[j][2];
                r += a[j][3];
                c += a[j][4];
                v.push_back(j+1);
            }
        }

        if(check(q, w, e, r) == true) {
            // cout << c << "\n";

            if(ret == c) {
                if(ret2 > v) {
                    ret2 = v;
                }
            }

            if(ret > c) {
                ret = c;
                ret2 = v;
            }
        }
    }

    if(ret == 987654321) {
        cout << -1 << "\n";
        return 0;
    }

    cout << ret << "\n";
    for(int i : ret2) {
        cout << i << " ";
    }
    cout << "\n";
}