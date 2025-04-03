#include <bits/stdc++.h>
using namespace std;

int n, k;
int visited[100004];
int cnt[100004];

int main() {
    cin >> n >> k;

    if(n == k) {
        cout << 0 << "\n";
        cout << 1 << "\n";
        return 0;
    }
    
    visited[n] = 1;
    cnt[n] = 1;
    queue<int> q;
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
                visited[there] = visited[now] + 1;
                // 이전 위치의 경우의 수를 다음 위치에 더해줌
                cnt[there] += cnt[now];
            }
            // 이전에 방문한 적이 있지만, 최단 거리로 도달 가능한 경우라면 경우의 수를 더해준다
            else if(visited[there] == visited[now] + 1) {
                cnt[there] += cnt[now];
            }
        }
    }

    cout << visited[k] - 1 << '\n';
    cout << cnt[k] << "\n";
}