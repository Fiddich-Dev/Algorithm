#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v;
int from, to;

int here;

vector<pair<int, int>> ret;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> from >> to;

        v.push_back({to, from});
    }

    sort(v.begin(), v.end());


    ret.push_back({v[0].first, v[0].second});
    here = v[0].first;

    for(int i = 1; i < n; i++) {
        if(v[i].second >= here) {
            ret.push_back({v[i].first, v[i].second});
            here = v[i].first;
        }
    }

    cout << ret.size() << "\n";
}