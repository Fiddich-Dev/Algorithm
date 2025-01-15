#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll temp1, temp2;
vector<pair<ll, ll>> v;

ll ret;

ll from, to;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        v.push_back({temp1, temp2});
    }

    sort(v.begin(), v.end());

    from = v[0].first;
    to = v[0].second;

    for(int i = 1; i < n; i++) {
        if(v[i].first <= to && v[i].second >= to) {
            to = v[i].second;
        }
        else if(v[i].first > to) {

            ret += to - from;

            from = v[i].first;
            to = v[i].second;
        }
    }
    ret += to - from;

    cout << ret << "\n";
}