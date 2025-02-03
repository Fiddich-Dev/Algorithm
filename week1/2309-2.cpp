#include <bits/stdc++.h>
using namespace std;

int temp;
vector<int> v;
pair<int, int> ret;
int sum;


void combi(int start, vector<int> b) {
    if(b.size() == 2) {
        if(sum - b[0] - b[1] == 100) {
            ret.first = b[0];
            ret.second = b[1];
        }
        return;
    }
    for(int i = start+1; i < 9; i++) {
        b.push_back(v[i]);
        combi(i, b);
        b.pop_back();
    }
}


int main() {
    for(int i = 0; i < 9; i++) {
        cin >> temp;
        v.push_back(temp);
        sum += temp;
    }

    vector<int> b;
    combi(-1, b);

    sort(v.begin(), v.end());

    for(int i : v) {
        if(i == ret.first || i == ret.second) {
            continue;
        }
        cout << i << "\n";
    }
}