#include <bits/stdc++.h>
using namespace std;

int n;
int p, d;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int ret;


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end());

    // 우선순위 큐의 사이즈는 현재 고른 강의의 데드라인 보다 작거나 같아야한다
    for(int i = 0; i < n; i++) {
        pq.push(v[i].second);

        if(pq.size() > v[i].first) {
            pq.pop();
        }
    }

    while(pq.size()) {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << "\n";
}