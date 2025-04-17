#include <bits/stdc++.h>
using namespace std;

int n, k;
string a[54];
int ret;

bool check(string s, vector<char> b) {
    for(char c : s) {
        // 고른 알파벳 이외에 알파벳이 s에 포함되어있을때
        if(find(b.begin(), b.end(), c) == b.end()) {
            return false;
        }
    }
    return true;
}

void combi(int start, vector<char> b) {
    if(b.size() == k) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(check(a[i], b) == true) {
                cnt++;
            }
        }
        ret = max(ret, cnt);
        return;
    }
    // a, n, t, i, c를 포함해서 k개의 알파벳 뽑기
    for(int i = start + 1; i < 26; i++) {
        if(i == 'a'-'a' || i == 'n'-'a' || i == 't'-'a' || i == 'i'-'a' || i == 'c'-'a') {
            continue;
        }
        b.push_back(i + 'a');
        combi(i, b);
        b.pop_back();
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<char> v = {'a', 'n', 't', 'i', 'c'};
    combi(-1, v);

    cout << ret << "\n";
}