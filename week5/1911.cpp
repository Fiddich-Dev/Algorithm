#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, l;
int s, e;

ll ret;

vector<pair<int, int>> v;

int main() {
    cin >> n >> l;

    for(int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());

    int now = 0;

    for(int i = 0; i < n; i++) {
        now = max(now, v[i].first);

        while(now < v[i].second) {
            now += l;
            ret++;
        }
        
    }

    cout << ret << "\n";
}