#include <bits/stdc++.h>
using namespace std;


int n;
int a[1004];
int cnt[1004];
int prev_list[1004];
int idx;
vector<int> v;
int ret;


void go(int idx) {
    if(idx == -1) {
        return;
    }
    v.push_back(a[idx]);
    go(prev_list[idx]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(&cnt[0], &cnt[0] + 1004, 1);
    fill(&prev_list[0], &prev_list[0] + 1004, -1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
                prev_list[i] = j;
            }
        }
        if(ret < cnt[i]) {
            ret = cnt[i];
            idx = i;
        }
    }

    cout << ret << "\n";

    int i = idx;
    for(; prev_list[i] != -1; i = prev_list[i]) {
        v.push_back(a[i]);
    }
    v.push_back(a[i]);

    reverse(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

}