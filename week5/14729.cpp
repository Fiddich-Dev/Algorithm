#include <bits/stdc++.h>
using namespace std;

int n;
double score;
priority_queue<double> pq;
vector<double> ret;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> score;

        if(pq.size() < 7) {
            pq.push(score);
        }
        else {
            pq.push(score);
            pq.pop();
        }
    }

    for(int i = 0; i < 7; i++) {
        ret.push_back(pq.top());
        pq.pop();
    }

    reverse(ret.begin(), ret.end());

    cout << fixed << setprecision(3);

    for(double i : ret) {
        cout << i << "\n";
    }
}