#include <bits/stdc++.h>
using namespace std;


int n;
int a[1004];
int cnt[1004];
int ret;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fill(&cnt[0], &cnt[0] + 1004, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && cnt[i] < cnt[j] + 1) {
                cnt[i] = cnt[j] + 1;
            }
        }
        ret = max(ret, cnt[i]);
    }

    cout << ret << "\n";
}