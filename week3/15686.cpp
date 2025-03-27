#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[54][54];

// 모든 치킨집
vector<pair<int, int>> c;
// 집
vector<pair<int, int>> h;

int ret = 1e9;


void combi(int start, vector<pair<int, int>> b) {
    if(b.size() == m) {
        int sum = 0;
        for(int i = 0; i < h.size(); i++) {
            int mn = 1e9;
            for(int j = 0; j < m; j++) {
                mn = min(mn, abs(h[i].first - b[j].first) + abs(h[i].second - b[j].second));
            }    
            sum += mn;
        }
        ret = min(ret, sum);
        return;
    }
    for(int i = start+1; i < c.size(); i++) {
        b.push_back(c[i]);
        combi(i, b);
        b.pop_back();
    }
}


// 0은 빈 칸, 1은 집, 2는 치킨집
int main() {

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 1) {
                h.push_back({i, j});
            }
            else if(a[i][j] == 2) {
                c.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> v;
    combi(-1, v);

    cout << ret << "\n";
}