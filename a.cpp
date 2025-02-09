#include <bits/stdc++.h>
using namespace std;

int n, c;
int temp;
vector<int> v;
map<int, int> m_fre;
map<int, int> m_idx;

// 빈도가 큰 수가 먼저온다
// 빈도가 같으면 먼저 입력된 수가 먼저 온다
bool compare(int r, int l) {
    if(m_fre[r] > m_fre[l]) {
        return true;
    }
    else if(m_fre[r] < m_fre[l]) {
        return false;
    }
    else {
        if(m_idx[r] < m_idx[l]) {
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
        m_fre[temp]++;
        if(m_idx[temp] == 0) {
            m_idx[temp] = i+1;
        }
    }

    sort(v.begin(), v.end(), compare);

    for(int i : v) {
        cout << i << " ";
    }
    cout << "\n";
}