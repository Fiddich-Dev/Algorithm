#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
vector<int> v;
int sum;
int mx;
int ret = INT_MAX;


bool check(int mid) {
    int s = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s + v[i] <= mid) {
            s += v[i];
        }
        else {
            cnt++;
            s = 0;
            s += v[i];
        }
    }
    if(s != 0) {
        cnt++;
    }

    return cnt <= m;
}


int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        sum += temp;
        mx = max(mx, temp);
    }

    int l = mx;
    int r = sum;
    // 인출금액
    int mid;

    while(l <= r) {
        mid = (l + r) / 2;

        if(check(mid)) {
            r = mid - 1;
            ret = min(ret, mid);
        }
        else {
            l = mid + 1;
        }
    }
    cout << ret << "\n";
}