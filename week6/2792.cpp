#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int a[300004];
int ret = 987654321;


bool check(int mid) {
    int num = 0;
    for(int i = 0; i < m; i++) {
        num += a[i] / mid;
        if(a[i] % mid) {
            num++;
        }
    }

    if(num <= n) {
        return true;
    }
    else {
        return false;
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int left = 1;
    int right = 0;
    int mid;

    for(int i = 0; i < m; i++) {
        cin >> a[i];
        right = max(right, a[i]);
    }

    while(left <= right) {
        mid = left + (right - left) / 2;

        if(check(mid)) {
            ret = min(ret, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ret << "\n";
}