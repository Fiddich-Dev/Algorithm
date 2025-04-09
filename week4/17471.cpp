#include <bits/stdc++.h>
using namespace std;

int n;
int a[13];
vector<int> adj[13];
int k;
int temp;
// 1구역 지역 번호
vector<int> v1;
// 2구역 지역 번호
vector<int> v2;
int visited[13];
int comp[13];

int cnt;

int ret = 1e9;


int dfs(int here, int value) {
    cnt++;
    int sum = a[here];
    visited[here] = 1;
    

    for(int there : adj[here]) {

        if(visited[there] == 0 && comp[there] == value) {
            sum += dfs(there, value);
        }
    }
    return sum;
}


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> k;
        for(int j = 0; j < k; j++) {
            cin >> temp;
            adj[i].push_back(temp);
        }
    }

    // 두 구역으로 나누기
    // 000000과 111111은 제외
    for(int i = 1; i < (1 << n)-1; i++) {
        v1.clear();
        v2.clear();
        
        fill(&comp[0], &comp[0]+13, 0);
        fill(&visited[0], &visited[0]+13, 0);
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                v1.push_back(j+1);
                comp[j+1] = 1;
            }
            else {
                v2.push_back(j+1);
                comp[j+1] = 2;
            }
        }
        // 나눌 수 있는 경우인지 확인
        cnt = 0;

        int p1 = dfs(v1[0], 1);
        int p2 = dfs(v2[0], 2);

        if(cnt == n) {
            ret = min(ret, abs(p1 - p2));
        }

    }

    if(ret == 1e9) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
}