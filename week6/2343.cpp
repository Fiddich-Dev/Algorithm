#include <bits/stdc++.h>
using namespace std;

int n, m;
int temp;
int mx;
vector<int> v;
int sum;
int ret = 987654321;

bool check(int mid) {
    // 블루레이 개수
    int cnt = 0;
    // 블루레이에 강의가 차지하는 공간
    int a = 0;
    for(int i = 0; i < n; i++) {
        if(a + v[i] <= mid) {
            a += v[i];
        }
        else {
            cnt++;
            a = 0;
            a += v[i];
        }
    }
    if(a != 0) {
        cnt++;
    }

    return cnt <= m;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        mx = max(mx, temp);
        sum += temp;
        v.push_back(temp);
    }

    int left = mx;
    int right = sum;
    int mid;

    while(left <= right) {
        mid = (left + right) / 2;
        if(check(mid)) {
            right = mid - 1;
            ret = min(ret, mid);
        }
        else {
            left = mid + 1;
        }
    }

    cout << ret << "\n";
}