#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[54][54];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int ret = 987654321;

// 치킨집의 좌표를 입력받으면 도시의 치킨거리를 return
// 치킨 거리는 집에서 치킨집 중의 최소거리
int dist(vector<pair<int, int>> b) {
    int sum = 0;
    for(pair<int, int> h : home) {
        int temp = 987654321;
        for(pair<int, int> c : b) {
            temp = min(temp, abs(h.first - c.first) + abs(h.second - c.second));
        }
        sum += temp;
    }
    return sum;
}

void combi(int start, vector<pair<int, int>> b) {
    if(b.size() == m) {
        ret = min(ret, dist(b));
        return;
    }
    for(int i = start+1; i < chicken.size(); i++) {
        b.push_back({chicken[i].first, chicken[i].second});
        combi(i, b);
        b.pop_back();
    }
}

// 0은 빈 칸, 1은 집, 2는 치킨집이다.
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) {
                chicken.push_back({i, j});
            }
            else if(a[i][j] == 1) {
                home.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> v;
    combi(-1, v);

    cout << ret << "\n";

}

