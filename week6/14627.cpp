#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int s, c;
int temp;
vector<int> v;
int m;

ll sum;
ll ret;

bool check(ll mid) {
    int cnt = 0;
    for(int i = 0; i < s; i++) {
        cnt += v[i] / mid;
    }

    return cnt >= c;
}

int main() {
    cin >> s >> c;
    for(int i = 0; i < s; i++) {
        cin >> temp;
        sum += temp;
        m = max(m, temp);
        v.push_back(temp);
    }

    ll l = 1;
    ll r = m;
    ll mid;

    while(l <= r) {
        mid = (l + r) / 2;
        if(check(mid)) {
            l = mid + 1;
            ret = max(ret, mid);
        }
        else {
            r = mid - 1;
        }
    }

    cout << sum - ret * c << "\n";
}