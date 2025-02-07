#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
int lis[104];
int len;
vector<pair<int, int>> v;

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        auto pos = lower_bound(&lis[0], &lis[0] + len, v[i].second);
        if(*pos == 0) {
            len++;
        }
        *pos = v[i].second;
    }

    cout << n - len << "\n";

}

