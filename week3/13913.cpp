#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[100004];
int pre[100004];

int main() {
    cin >> n >> k;

    if(n == k) {
        cout << 0 << "\n";
        cout << n << "\n";
        return 0;
    }
    
    visited[n] = 1;
    queue<int> q;
    pre[n] = -1;
    q.push(n);

    while(q.size()) {
        int now = q.front();
        q.pop();

        for(int next : {-1, 1, now}) {
            int there = now + next;

            if(there < 0 || there > 100000) {
                continue;
            }

            if(visited[there] == 0) {
                q.push(there);
                pre[there] = now;
                visited[there] = visited[now] + 1;
            }
        }
    }

    vector<int> ret;

    ret.push_back(k);
    int now = k;

    while(pre[now] != -1) {
        ret.push_back(pre[now]);
        now = pre[now];
    }

    reverse(ret.begin(), ret.end());

    cout << visited[k] - 1 << "\n";

    for(int i : ret) {
        cout << i << " ";
    }
    cout << "\n";
}