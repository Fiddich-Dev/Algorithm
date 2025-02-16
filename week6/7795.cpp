#include <bits/stdc++.h>
using namespace std;

int t;
int n, m;
vector<int> a;
vector<int> b;
int temp;
int ret;


int binary_search(int i) {
    return lower_bound(b.begin(), b.end(), i) - b.begin();
}


int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        a.clear();
        b.clear();
        ret = 0;

        for(int j = 0; j < n; j++) {
            cin >> temp;
            a.push_back(temp);
        }
        for(int j = 0; j < m; j++) {
            cin >> temp;
            b.push_back(temp);
        }

        sort(b.begin(), b.end());

        for(int j = 0; j < n; j++) {
            ret += binary_search(a[j]);
        }
        cout << ret << "\n";
    }

}