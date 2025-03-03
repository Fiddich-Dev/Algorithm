#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int n) {
    string s = to_string(n);
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '6') {
            cnt++;
        }
        else {
            cnt = 0;
        }
        if(cnt == 3) {
            return true;
        }
    }
    return false;
}

int solve(int n) {
    int temp = 0;
    int cnt = 0;
    while(true) {
        if(check(temp) == true) {
            cnt++;
        }

        if(cnt == n) {
            return temp;
        }

        temp++;
    }
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    cout << solve(n) << "\n";
}