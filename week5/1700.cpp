#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int temp;
vector<int> v;
int a[104];

priority_queue<int, vector<int>, greater<int>> pq[104];
vector<int> concent;

int visited[104];
const int INF = 987654321;

int cnt;

int ret;

int main() {
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        // 콘센트에 안꽂여있으면
        if(visited[a[i]] == 0) {
            // 콘센트에 빈자리가 없으면
            if(v.size() == n) {
                // 가장 나중에 다시 사용될 기기의 위치
                int last_idx = 0;
                // 교체할 기기
                int pos;

                // 콘센트에 꽂힌 전자기기를 돌며
                for(int _a : v) {
                    // 현재 기기가 다시 사용될 위치
                    int here_pick = INF;
                    // 미래에 쓸 전자기기를 돌며
                    for(int j = i+1; j < k; j++) {
                        // 콘센트에 꽂힌 전자기기와 미래에 쓸 전자기기가 같을떄
                        if(_a == a[j]) {
                            here_pick = j;
                            break;
                        }
                    }
                    
                    if(last_idx < here_pick) {
                        last_idx = here_pick;
                        pos = _a;
                    }
                }
                // 가장 먼 미래에 사용될 전자기기 콘센트에서 제거
                visited[pos] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), pos));
            }
            // 콘센트에 꽂기
            v.push_back(a[i]);
            visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";

}