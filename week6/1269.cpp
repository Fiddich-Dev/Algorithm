#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;
vector<int> b;
int temp;
int cnt;

// a의 원소로 b에서 탐색
bool binary_search(int i) {
    int l = 0;
    int r = m - 1;
    int mid;

    while(l <= r) {
        mid = (l + r) / 2;
        if(b[mid] == i) {
            return true;
        }
        else if(b[mid] < i) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}


int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < n; i++) {
        if(binary_search(a[i]) == true) {
            cnt++;
        }
    }

    cout << n + m - 2*cnt << "\n";

}