#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int temp;
vector<int> v;
int a[104];

priority_queue<int, vector<int>, greater<int>> pq[104];
vector<int> concent;

int ret;

int main() {
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> temp;
        v.push_back(temp);
        pq[temp].push(i);
    }
    // 이미 꽂혀있다는 뜻 find(concent.begin(), concent.end(), x) != concent.end()
    for(int i = 0; i < k; i++) {
        // 콘센트가 비어있으면
        if(concent.size() == 0) {
            concent.push_back(v[i]);
            pq[v[i]].pop();
        }
        // 콘센트의 빈자리가 있고 안꽃혀있을때
        else if(concent.size() < n && find(concent.begin(), concent.end(), v[i]) == concent.end()) {
            concent.push_back(v[i]);
            pq[v[i]].pop();
        }
        // 콘센트 빈자리가 없고 안꽃혀있을때
        else if(concent.size() >= n && find(concent.begin(), concent.end(), v[i]) != concent.end()) {
            int a = 0;
            for(int j = 0; j < n; j++) {
                // 큐가 비어있는거 최우선
                // 다음은 큐 탑의 크기가 큰거
                if(pq[concent[j]].size() == 0) {
                    a = concent[j];
                    break;
                }
                else {
                    a = max(a, pq[concent[j]].top());
                }
            }
            
        }

        // 콘센트 빈자리가 없고 꽃혀있을때
        else if(concent.size() >= n && find(concent.begin(), concent.end(), v[i]) != concent.end()) {
            pq[v[i]].pop();
        }

        // 콘센트 빈자리가 있고 꽃혀있을때
        else if(concent.size() < n && find(concent.begin(), concent.end(), v[i]) != concent.end()) {
            pq[v[i]].pop();
        }

        if(concent.size() < n && find(concent.begin(), concent.end(), v[i]) == concent.end()) 

        if(concent.size() < n && find(concent.begin(), concent.end(), v[i]) == concent.end()) {
            concent.push_back(v[i]);
            pq[v[i]].pop();
        }
        else if(find(concent.begin(), concent.end(), v[i]) == )
    }



}