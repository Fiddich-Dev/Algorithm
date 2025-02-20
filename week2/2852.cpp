#include <bits/stdc++.h>
using namespace std;

int n;
int temp1;
string temp2;
pair<int, int> score;
vector<pair<int, int>> v1;
vector<int> v2;

int ret1;
int ret2;

string solve(int i) {
    int m = i / 60;
    string m1 = to_string(m);
    if(m1.size() < 2) {
        m1 = "0" + m1;
    }

    int s = i % 60;
    string s1 = to_string(s);
    if(s1.size() < 2) {
        s1 = "0" + s1;
    }

    return m1 + ":" + s1;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        if(temp1 == 1) {
            score.first++;
        }
        else {
            score.second++;
        }
        int time = atoi(temp2.substr(0,2).c_str()) * 60 + atoi(temp2.substr(3).c_str()); 

        v1.push_back(score);
        v2.push_back(time);
    }
    v1.push_back(score);
    v2.push_back(48 * 60);

    for(int i = 0; i < v1.size() - 1; i++) {
        if(v1[i].first > v1[i].second) {
            ret1 += v2[i+1] - v2[i];
        }
        else if(v1[i].first < v1[i].second) {
            ret2 += v2[i+1] - v2[i];
        }
    }

    cout << solve(ret1) << "\n";
    cout << solve(ret2) << "\n";
}