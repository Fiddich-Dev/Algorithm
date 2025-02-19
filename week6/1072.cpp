#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y;
ll z;
ll ret = 1e9;

int main() {
    cin >> x >> y;
    z = y * 100 / x;

    ll l = 1;
    ll r = 1e9;
    ll mid;
    // 바뀐 확률
    ll a;

    a = (y + r) * 100 / (x + r);
    if(a == z) {
        cout << -1 << "\n";
        return 0;
    }

    while(l <= r) {
        mid = (l + r) / 2;
        a = (y + mid) * 100 / (x + mid);
        // 너무 적게 게임했을때
        if(z == a) {
            l = mid + 1;
        }
        // 충분히 게임했을때
        else {
            r = mid - 1;
            ret = min(ret, mid);
        }
    }
    cout << ret << "\n";
}