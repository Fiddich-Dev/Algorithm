#include <bits/stdc++.h>
using namespace std;

int n;
int start, t;
vector<pair<int, int>> v;

int now;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> start >> t;
        v.push_back({start, t});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        now = max(v[i].first, now) + v[i].second;
    }

    cout << now << "\n";
}