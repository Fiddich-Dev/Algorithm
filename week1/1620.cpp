#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
vector<string> v;
map<string, int> m1;
string temp;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
        m1[s] = i + 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> temp;
        // 문자일때
        if(atoi(temp.c_str()) == 0) {
            cout << m1[temp] << "\n";
        }
        // 숫자일때
        else {
            cout << v[atoi(temp.c_str()) - 1] << "\n";
        }
    }
}