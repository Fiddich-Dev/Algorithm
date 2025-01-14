#include <bits/stdc++.h>
using namespace std;

int n, k;
int m, v;
int c;

vector<pair<int, int>> crystals;
vector<long long> bags;

priority_queue<int> pq;

long long ret;

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> m >> v;
        crystals.push_back({m, v});
    }
    for(int i = 0; i < k; i++) {
        cin >> c;
        bags.push_back(c);
    }

    sort(crystals.begin(), crystals.end());
    sort(bags.begin(), bags.end());


    int j = 0;
    for(int i = 0; i < k; i++) {
        for(; j < n; j++) {
            if(crystals[j].first <= bags[i]) {
                pq.push(crystals[j].second);
            }
            else {
                break;
            }
        }

        if(pq.size()) {
            ret += pq.top();
            pq.pop();
        }
    }

    cout << ret << "\n";
}