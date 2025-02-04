#include <bits/stdc++.h>
using namespace std;

int t;
int n;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        map<string, int> m;
        set<string> st;
        int ret = 1;

        for(int j = 0; j < n; j++) {
            cin >> s1 >> s2;
            m[s2]++;
            st.insert(s2);
        }

        for(pair<string, int> p : m) {
            ret *= p.second + 1;
        }

        ret--;
        cout << ret << "\n";
    }
}