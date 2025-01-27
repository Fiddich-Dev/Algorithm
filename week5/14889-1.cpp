#include <bits/stdc++.h>
using namespace std;

int n;
int a[24][24];

int m = 987654321;


int solve(vector<int> v) {

    int sum = 0;

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            sum += a[v[i]][v[j]];
        }
    }
    return sum;
}

int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < (1 << n); i++) {
        vector<int> start;
        vector<int> link;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                start.push_back(j);
            }
            else {
                link.push_back(j);
            }
        }

        if(start.size() == link.size()) {
            m = min(m, abs(solve(start) - solve(link)));
        }
    }

    cout << m << "\n";

}