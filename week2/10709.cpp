#include <bits/stdc++.h>
using namespace std;

int h, w;
string s;

void solve(string s) {
    // 구름을 발견하면 1로 바꿈
    int flag = 0;
    int cnt = 0;
    vector<int> ret;

    for(int i = 0; i < w; i++) {
        if(s[i] == 'c') {
            flag = 1;
            cnt = 0;
            ret.push_back(0);
        }
        else if(s[i] == '.') {
            if(flag == 0) {
                ret.push_back(-1);
            }
            else if(flag == 1) {
                cnt++;
                ret.push_back(cnt);
                
            }
        }
    }

    for(int i : ret) {
        cout << i << " ";
    }
    cout << "\n";
}


int main() {
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        cin >> s;
        solve(s);
    }


}