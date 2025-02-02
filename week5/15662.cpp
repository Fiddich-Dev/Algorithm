#include <bits/stdc++.h>
using namespace std;

int t;
vector<int> v[1004];
string s;

int k;
int a, b;

vector<vector<int>> vv;

int ret;

void roll(int n, int d) {
    // 시계 방향
    if(d == 1) {
        rotate(v[n].begin(), v[n].end() - 1, v[n].end());
    }
    // 반시계 방향
    else {
        rotate(v[n].begin(), v[n].begin() + 1, v[n].end());
    }
}

// 2번, 6번 인덱스 확인
// 다르면 회전
void check() {
    vector<int> temp;
    temp.push_back(0);
    for(int i = 0; i < t-1; i++) {
        if(v[i][2] != v[i+1][6]) {
            temp.push_back(i+1);
        }
        else {
            vv.push_back(temp);
            temp.clear();
            temp.push_back(i+1);
        }
    }
    // 마지막 톱니바퀴 추가
    vv.push_back(temp);

}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> s;
        for(int j = 0; j < 8; j++) {
            v[i].push_back(s[j] - '0');
        }
    }
    cin >> k;

    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        a--;

        vv.clear();
        check();

        int c = 0;
        int flag;

        for(int j = 0; j < vv.size(); j++) {
            if(find(vv[j].begin(), vv[j].end(), a) != vv[j].end()) {
                c = j;
                break;
            }
        }

        // 돌리는 톱니바퀴와 거리차이가 짝수면 같은방향으로 돈다
        if((a - vv[c][0]) % 2 == 0) {
            flag = b;
        }
        else {
            flag = b * (-1);
        }

        // 다음 톱니바퀴는 반대로 돈다
        for(int j : vv[c]) {
            roll(j, flag);
            flag *= -1;
        }
    }

    for(int i = 0; i < t; i++) {
        if(v[i][0] == 1) {
            ret++;
        }
    }
    cout << ret << "\n";
}